set ns [new Simulator]
set nf [open "out.nam" w]
$ns namtrace-all $nf
proc finish {} {
global ns nf
$ns flush-trace
close $nf
exec nam out.nam &
exit 0
}
set n0 [$ns node]
set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
$ns duplex-link $n0 $n2 2Mb 10ms DropTail
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n2 7Mb 20ms DropTail
Set tcp [newAgent/TCP]
$ns attach -agent $n0 $tcp
set sink
set null [newAgent/Null]
$ns attach -agent $n3 $null
$ns connect $udp $null
$ns at 0.1 "$ftp start"
$ns at 0.2 "$cbr start"
$ns at 4.0 "$ftp stop"
$ns at 4.5 "$cbr stop"
$ns at 5.0 "finish"
$ns run