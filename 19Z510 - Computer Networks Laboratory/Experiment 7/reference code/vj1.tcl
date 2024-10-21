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

# Create five nodes
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node] ;# New node (n4)

# Create links between the nodes
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail
$ns duplex-link $n3 $n4 2Mb 15ms DropTail ;# New link between n3 and n4
$ns duplex-link $n4 $n0 2Mb 15ms DropTail ;# New link between n4 and n0

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

# Attach an additional TCP agent and FTP application to n4
set tcp1 [new Agent/TCP]
$ns attach-agent $n4 $tcp1
set sink1 [new Agent/TCPSink]
$ns attach-agent $n2 $sink1
$ns connect $tcp1 $sink1

# Attach FTP traffic source to the new TCP agent (on node n4)
set ftp1 [new Application/FTP]
$ftp1 attach-agent $tcp1

# Schedule FTP events for the new connection
$ns at 1.5 "$ftp1 start"
$ns at 4.2 "$ftp1 stop"

# Call the finish procedure after 5 seconds of simulation time
$ns at 5.0 "finish"

# Print FTP and CBR settings
puts "FTP: 1.0s to 4.0s on n0->n3"
puts "CBR: 0.1s to 4.5s with packet size 1KB and rate 1Mbps on n1->n3"
puts "FTP: 1.5s to 4.2s on n4->n2"

# Run the simulation
$ns run