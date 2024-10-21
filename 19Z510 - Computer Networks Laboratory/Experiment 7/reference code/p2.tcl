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

set n1 [$ns node]
set n2 [$ns node]
set n3 [$ns node]
set n4 [$ns node]
$ns duplex-link $n1 $n2 2Mb 10ms DropTail
$ns duplex-link $n2 $n3 1.7Mb 20ms DropTail
$ns duplex-link $n3 $n4 2Mb 10ms DropTail
$ns duplex-link $n4 $n1 2Mb 10ms DropTail
set tcp1 [new Agent/TCP]
$ns attach-agent $n1 $tcp1
set tcp2 [new Agent/TCP]
$ns attach-agent $n2 $tcp2
set tcp3 [new Agent/TCP]
$ns attach-agent $n3 $tcp3
set tcp4 [new Agent/TCP]
$ns attach-agent $n4 $tcp4
set sink1 [new Agent/TCPSink]
$ns attach-agent $n2 $sink1
$ns connect $tcp1 $sink1
set sink2 [new Agent/TCPSink]
$ns attach-agent $n3 $sink2
$ns connect $tcp1 $sink2
set sink3 [new Agent/TCPSink]
$ns attach-agent $n4 $sink3
$ns connect $tcp1 $sink3
set sink4 [new Agent/TCPSink]
$ns attach-agent $n1 $sink4
$ns connect $tcp1 $sink4
set ftp1 [new Application /FTP]
$ftp1 attach-agent $tcp1
set ftp2 [new Application /FTP]
$ftp2 attach-agent $tcp2
set ftp3 [new Application /FTP]
$ftp3 attach-agent $tcp3
set ftp4 [new Application /FTP]
$ftp4 attach-agent $tcp4
$ns at 1.0 "$ftp1 start"
$ns at 4.0 "$ftp1 stop"
$ns at 1.0 "$ftp2 start"
$ns at 4.0 "$ftp2 stop"
$ns at 1.0 "$ftp3 start"
$ns at 4.0 "$ftp3 stop"
$ns at 1.0 "$ftp4 start"
$ns at 4.0 "$ftp4 stop"
$ns at 5.0 "finish"
$ns run