
## Aim:
To study basic Linux and Windows Powershell commands about networking


## Linux Commands

1. Ping: Checks connectivity to a host by sending ICMP (Internet Control Message Protocol) packets and waiting for replies.	

<img width="896" alt="ping" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/6485e575-0c76-4e3c-ba21-f80ea6f5cceb">

2. Netstat: Displays information about network connections, routing tables, and interfaces.

<img width="722" alt="netstat" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/3efed9d5-5000-48e5-81ed-2e937b83f327">

3. Hostname: Shows the hostname of the current machine.

<img width="218" alt="hostname" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/71678bce-a346-458f-9ef9-bb830b9682b5">

4. Ipconfig (Not Linux): This command is specific to Windows and doesn't work in Linux. Use `ifconfig` instead.

<img width="804" alt="ifconfig" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/589689d3-939b-4477-b0da-5da07e7738cc">

5. Nslookup: Looks up information about a domain name or IP address using the DNS (Domain Name System).

<img width="306" alt="nslookup" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/c80552c0-fc40-415d-95ad-c322f56f6876">

6. Route: Shows or manipulates the routing table used for network traffic.

<img width="715" alt="route" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/eb10ac91-c12c-4313-9420-aba2bf186443">

7. Arp: Displays or manipulates the Address Resolution Protocol (ARP) table, which maps IP addresses to MAC addresses.

<img width="518" alt="arp" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/6a12858d-00c7-4730-a624-255fb4675bd9">

8. Tracert (or Traceroute): Traces the route packets take to reach a destination, showing hops along the way.

<img width="1026" alt="traceroute" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/721ab4fe-d230-4c04-ad09-e1ad938b30bd">

9. NbtStat (Windows-specific): Not commonly used in Linux. It browses the NetBIOS name table on Windows networks.

10. Pathping: Combines features of ping and traceroute, providing more detailed information about the path to a destination.

11. Getmac: Might be a custom script or tool depending on your distribution. Use `ip addr show` to view network interface details including MAC addresses.

<img width="943" alt="ipaddrshow" src="https://github.com/akashShanmugraj/programming-notes/assets/65720968/b9e07a8d-c0fb-47d5-9e40-81019ffbe56d">

12. Netsh (Windows-specific): Primarily used for configuring network interfaces and routing on Windows.

  

Windows Powershell Commands:

  

1. Test-NetConnection: Similar to ping, checks network connectivity to a host.

2. Get-NetIPConfiguration: Shows information about network adapters and their IP configurations.

  

Additional Commands:

  

13. Ifdown: Brings down a network interface (disables it).

Example: `ifdown eth0` (disables the network interface eth0 - use with caution)

14. curl: Downloads files from URLs. Similar to `wget`.

Example: `curl https://example.com/file.txt` (downloads file.txt from the specified URL)

15. ssh: Establishes a secure shell connection to a remote server.

Example: `ssh user@server.com` (connects to [invalid URL removed] as user)

16. scp: Securely copies files between local and remote machines using SSH.

Example: `scp /path/to/file user@server.com:/destination/folder` (copies a file to the remote server)

17. sftp: Secure file transfer protocol, similar to SCP but provides interactive access for browsing and transferring files.

18. Tcpdump: Captures network traffic on a specified interface for analysis. Requires root privileges.

Example: `sudo tcpdump -i eth0` (captures traffic on interface eth0 - use with caution)