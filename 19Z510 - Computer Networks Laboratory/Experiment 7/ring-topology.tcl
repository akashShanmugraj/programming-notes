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
set nodes {}
for {set i 0} {$i < 5} {incr i} {
    lappend nodes [$ns node]
}

# Connect nodes in a ring topology
for {set i 0} {$i < 5} {incr i} {
    $ns duplex-link [lindex $nodes $i] [lindex $nodes [expr {($i + 1) % 5}]] 1Mb 10ms DropTail
}

# Create a UDP agent and attach it to the source node (n0)
set udp0 [new Agent/UDP]
$ns attach-agent [lindex $nodes 0] $udp0

# Create a CBR traffic source and attach it to udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0

# Create a Null agent which acts as a traffic sink and attach it to the destination node (n2)
set null0 [new Agent/Null]
$ns attach-agent [lindex $nodes 2] $null0

# Connect the UDP agent to the Null agent
$ns connect $udp0 $null0

# Schedule events for the CBR traffic source
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"

# Call the finish procedure after 5 seconds of simulation time
$ns at 5.0 "finish"

# Run the simulation
$ns run