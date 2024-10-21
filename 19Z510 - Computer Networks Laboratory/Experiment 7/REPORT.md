<p>Experiment 7<p>


<h1 align="center">NS2 (Network Simulator 2)</h1>

## Aim
To create and analyse virtual networks.

## Sample Source Code
```
set ns [new Simulator]
set nf [open out.nam w]
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
$ns duplex-link $n0 $n1 1Mb 10ms DropTail
set udp0 [new Agent/UDP]
$ns attach-agent $n0 $udp0
set cbr0 [new Application/Traffic/CBR]
$cbr0 set packetSize_ 500
$cbr0 set interval_ 0.005
$cbr0 attach-agent $udp0
set null0 [new Agent/Null]
$ns attach-agent $n1 $null0
$ns connect $udp0 $null0
$ns at 0.5 "$cbr0 start"
$ns at 4.5 "$cbr0 stop"
$ns at 5.0 "finish"
$ns run
```

## Sample Output



## Design and visualize the following in NS2

![image](https://github.com/user-attachments/assets/3cb05b4f-12a4-47dd-b914-5068c47c2e38)

### Source Code
```
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
```

### Output


## Ring Topology

### Source Code
```
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
```

### Output

## Result:
The program is successfully implemented.