# Create a simulator object
set ns [new Simulator]

# Open the NAM trace file
set nf [open out.nam w]
$ns namtrace-all $nf

# Define a 'finish' procedure
proc finish {} {
    global ns nf
    $ns flush-trace
    close $nf
    exec nam out.nam &
    exit 0
}

# Create four nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]

# Create links between the nodes
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail

# Attach TCP agent and FTP application to n0
set tcp0 [new Agent/TCP]
$ns attach-agent $n0 $tcp0
set sink0 [new Agent/TCPSink]
$ns attach-agent $n3 $sink0
$ns connect $tcp0 $sink0

# Attach FTP traffic source to TCP agent
set ftp0 [new Application/FTP]
$ftp0 attach-agent $tcp0

# Schedule FTP events
$ns at 1.0 "$ftp0 start"
$ns at 4.0 "$ftp0 stop"

# Attach UDP agent and CBR application to n1
set udp0 [new Agent/UDP]
$ns attach-agent $n1 $udp0
set null0 [new Agent/Null]
$ns attach-agent $n3 $null0
$ns connect $udp0 $null0

# Attach CBR traffic source to UDP agent
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 1000
$cbr0 set rate_ 1Mb
$cbr0 attach-agent $udp0

# Schedule CBR events
$ns at 0.1 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"

# Call the finish procedure after 5 seconds of simulation time
$ns at 5.0 "finish"

# Print FTP and CBR settings
puts "FTP: 1.0s to 4.0s"
puts "CBR: 0.1s to 4.5s with packet size 1KB and rate 1Mbps"

# Run the simulation
$ns run
