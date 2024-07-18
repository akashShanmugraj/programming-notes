# Experiment 1

## Aim
To understand the different types of network components, their characteristics, and how they function within a network.
## Network Basics

A **computer network** is a telecommunications network that enables computers to exchange data. Networks are formed by connecting computing devices using physical wires or cables, or wirelessly through radio waves or infrared signals. The best-known example of a computer network is the internet. Networks are fundamental to modern communication and resource sharing.

<img width="700" alt="ping" src="https://www.devry.edu/blog/what-is-computer-networking/_jcr_content/root/container/structured_container_161844580/content-col-1/container/image_2139742317_cop.coreimg.jpeg/1683960937845/pic-what-is-computer-networking-1.jpeg">
## Building Blocks of Networks

The essential components of a network include:

- **Nodes:** Computers and other devices connected within a network. Examples include computers, printers, and mobile devices.
- **Links:** The physical connections between nodes, established through mediums like coaxial cables or optical fibres.

## Types of Networks

Networks are categorised based on their size and coverage area:

- **Personal Area Networks (PANs):** Small networks connecting devices within a user's immediate vicinity (around 10 meters), such as laptops, mobile phones, and printers. PANs can include wired and wireless connections.

- **Local Area Networks (LANs):** Networks connecting computers and devices within a limited geographical area, like a home, office, or school. LANs typically employ Ethernet technology, offering high speeds (10 Mbps to 10 Gbps) over short distances (100-1000 meters).

- **Metropolitan Area Networks (MANs):** Larger networks extending across a city or metropolitan area, often formed by connecting multiple LANs.

- **Wide Area Networks (WANs):** Networks covering a vast geographical expanse, spanning cities, countries, or even continents. WANs utilise diverse communication channels, including telephone lines, cables, and airwaves. The internet is a prime example of a WAN.

<img width="700" alt="ping" src="https://www.brainwareuniversity.ac.in/blog/wp-content/uploads/2019/03/CN.png">
## Network Architecture

**Client-Server Architecture**

In a client-server architecture, devices communicate with each other through a central computer known as a server. The server, possessing high processing power, provides services to the other computers on the network, which are called clients.

**Peer-to-Peer Architecture**

In a peer-to-peer architecture, there is no distinction between clients and servers. Each node (computer or device on the network) can provide services to and request services from other nodes. This architecture facilitates the sharing of resources, data, and users, with each node having full control over network resources.

**Hybrid Architecture**

Hybrid architectures combine elements of both client-server and peer-to-peer architectures to leverage the advantages of both.

<img width="700" alt="ping" src="https://systemdesignschool.io/blog/peer-to-peer-architecture/client-server-vs-p2p.png">
## Network Topology

Network topology refers to the arrangement of nodes within a network, influencing how information is exchanged. There are several types of network topologies:

- **Bus Topology:** In a bus topology, all nodes connect to a single shared communication line, referred to as a bus. This setup allows any station to communicate with any other, though rules are necessary to manage simultaneous communication attempts. A break in the bus only impacts communication on either side of the break. The number of links in a bus topology is N+1, where N represents the number of nodes.

- **Star Topology:** A star topology centres around a central network controller, with each node connecting directly to it. Adding new nodes is straightforward – simply connect them to the controller. Communication between any two stations must pass through the controller. However, if the controller fails, the entire network is affected. A star topology has N links, where N represents the number of nodes.

- **Ring Topology:** Nodes in a ring topology connect in a point-to-point manner, forming a closed loop. Data transmission requires passing through each node in the ring until it reaches its destination. A malfunctioning node can disrupt the entire network. The number of links in a ring topology is equal to the number of nodes.

- **Mesh Topology:** Mesh topologies can be either full mesh or partial mesh. In a full mesh, every node has a direct connection to every other node, offering alternate data routes and robust fault tolerance. A partial mesh, however, only connects some nodes directly while others rely on intermediary nodes. This topology is well-suited for long-distance networking due to its support for backup and rerouting capabilities. However, the number of connections increases significantly with the number of nodes.

- **Tree Topology:** Tree topologies arrange nodes in a hierarchical structure, resembling a tree. The root node sits at the top, with subordinate nodes (child nodes) branching out below.

- **Hybrid Topology:** Combining two or more basic topologies results in a hybrid topology. This approach allows network designers to leverage the strengths of different topologies to suit specific needs. For example, a hybrid topology might combine the resilience of a mesh network with the cost-effectiveness of a star network in different sections.

<img width="700" alt="ping" src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/97/NetworkTopologies.svg/600px-NetworkTopologies.svg.png">
## Network Components

Network components are the fundamental building blocks that enable communication and resource sharing in a network. These components can be broadly categorized into hardware and software, each playing a crucial role in ensuring the smooth operation of a network. The sources provide a detailed overview of various network components, particularly focusing on hardware aspects.

**Hardware Components:**

- **Network Interface Card (NIC):** A NIC acts as the interface between a computer and the network medium, enabling the computer to send and receive data. It converts the computer's data into electronic signals suitable for transmission over the network medium, which could be wired or wireless. Every device on a network requires a NIC to communicate.

- **Repeater:** A repeater amplifies and regenerates a signal to extend its transmission distance. It effectively counteracts signal degradation over long distances, ensuring reliable communication in networks spread over large areas. Repeaters are typically used in wired networks, particularly those based on twisted-pair Ethernet cabling, where signal strength weakens after a certain distance.

- **Hub:** A hub serves as a central connection point for multiple devices in a network. When a hub receives data on one port, it transmits that data to all other connected ports without considering the intended destination. While this simplicity makes hubs inexpensive, it also leads to inefficiencies and potential security concerns.

- **Switch:** A switch operates similarly to a hub but with enhanced intelligence. Unlike a hub, a switch forwards data only to the intended recipient based on their MAC address, improving efficiency and security. Switches learn and store the MAC addresses of connected devices, enabling them to create direct data paths and reduce unnecessary network traffic.

- **Bridge:** A bridge connects two or more network segments, enabling communication between devices located on different segments. Bridges examine incoming data packets and forward them only to the segment containing the intended destination. They play a crucial role in segmenting networks, improving performance, and enhancing security by isolating traffic.

- **Router:** A router acts as a traffic director in a network. It forwards data packets between different networks, determining the optimal path for data transmission based on factors such as network congestion and available bandwidth. Routers are essential for internet connectivity as they enable communication between a local network and the wider internet.

- **Gateway:** A gateway serves as an entry and exit point for a network, connecting different networks that use dissimilar protocols. It acts as a translator, converting data formats and protocols as needed to enable communication between the connected networks.

- **Modem:** A modem (modulator-demodulator) facilitates communication between a computer and a telephone line or other communication channels. It converts digital data from the computer into analog signals for transmission over the communication channel and vice versa. Modems are crucial for internet access using technologies like DSL and dial-up.

- **Node:** Any device connected to a network that can send and receive data is considered a node. This includes computers, printers, servers, and any other device with network connectivity.

- **Host:** A host is a specific type of node that provides services and resources to other nodes on the network. It typically refers to computers that run network applications and serve user requests. The terms 'host' and 'node' are often used interchangeably, but 'host' implies a more active role in providing network services.

- **Client/Server:** In a client-server architecture, a client is a device that requests services from a server. The server, in turn, fulfils these requests. This model is prevalent in various network services, such as web browsing (client requests web pages from web servers) and email (client sends and receives emails via email servers).

- **Access Point:** An access point acts as a bridge between wired and wireless networks. It allows wireless devices to connect to a wired LAN, extending the network's reach and enabling mobility. The data transfer speed of an access point depends on the chosen wireless technology, such as Wi-Fi standards like 802.11ac or 802.11ax.

- **Port:** Ports represent the physical input/output interfaces on network devices. They act as connection points for cables and other network components.

- **Network Transmission Medium:** The network transmission medium refers to the physical pathway over which data travels in a network. It can be wired, such as twisted-pair cable, coaxial cable, and fibre optic cable, or wireless, utilising electromagnetic waves for transmission.

<img width="700" alt="ping" src="https://findtodaysnotes.wordpress.com/wp-content/uploads/2023/10/image-23.png?w=1024">
## Transmission Media: Wired vs. Wireless

**Network Transmission Medium**

- The term refers to the physical channels through which network signals are carried.
- The term "link" often refers to the shared medium and the rules governing transmissions on that medium.

There are two types of transmission media: wired and wireless.

### Wired Transmission Media

- Also known as guided media, these media provide a physical conduit for signal transmission between devices.
- Examples include twisted-pair cable, coaxial cable, and fibre-optic cable.
- Signals travelling along these media are contained and directed by the physical boundaries of the medium.

**Types of Wired Transmission Media**

**1. Twisted Pair Cable**

- Consists of two insulated copper conductors twisted together to reduce electromagnetic interference.
- One wire carries the signal, while the other serves as a ground reference.
- Twisted pair cable is the most common, cost-effective, lightweight, and easy-to-install type.

**Types of Twisted Pair Cable:**

- **Unshielded Twisted Pair (UTP):** The most prevalent type, with an RJ45 connector.
- **Shielded Twisted Pair (STP):** Includes a metal foil or braided mesh shielding to enhance signal quality and reduce noise interference, making it bulkier and more expensive than UTP.

**Applications of Twisted Pair Cable:**

- Telephone lines for voice and data transmission.
- DSL lines for high-data-rate connections.
- Local Area Networks (LANs), such as 10Base-T and 100Base-T.

**2. Coaxial Cable**

- Supports higher frequency signals than twisted pair cable.
- Consists of a central conductor (copper) surrounded by an insulating sheath, an outer conductor (metal foil or braid), and a protective plastic cover.
- The outer conductor acts as a shield against noise interference.

**Types of Coaxial Cable:**

- **Baseband:** A 50-ohm coaxial cable primarily used for digital transmission in LANs, transmitting a single signal at high speed.
- **Broadband:** Employs analog transmission over standard cable television cabling, enabling multiple simultaneous signals using different frequencies, covering larger areas than baseband coaxial cable.

**Coaxial Cable Connector:**

- The most common connector is the Bayonet-Neill-Concelman (BNC) connector.
- Other types include BNC T connectors and BNC terminators.

**Applications of Coaxial Cable:**

- Traditional cable TV networks.
- Early Ethernet LANs (10Base-2 or Thin Ethernet using RG-58 cable and 10Base5 or Thick Ethernet using RG-11 cable).

**3. Fibre-Optic Cable**

- Made of glass or plastic, transmits signals as light.
- Uses reflection to guide light through a core (glass or plastic) surrounded by a cladding (less dense glass or plastic).
- The density difference ensures that light beams travelling through the core are reflected within, enabling long-distance, high-bandwidth data transmission.

**Fibre-Optic Cable Connectors:**

- Subscriber Channel (SC) connector: Used for cable TV with a push/pull locking mechanism.
- Straight-Tip (ST) connector: Connects cables to networking devices with a bayonet locking system, more reliable than SC.
- MT-RJ connector: Similar in size to RJ45.

**Applications of Fibre-Optic Cable:**

- Backbone networks requiring high bandwidth.
- Hybrid networks combining fibre-optic cable for the backbone and coaxial cable for user connections.
- High-speed LANs, including 100Base-FX (Fast Ethernet) and 1000Base-X.

### Wireless Transmission Media

- Referred to as unguided media, these transmit electromagnetic waves without a physical conductor.
- Signals are broadcasted through free space, accessible to any device with a receiver.

**Types of Wireless Transmission Media**

**1. Radio Waves**

- Electromagnetic waves ranging from 3 kHz to 1 GHz.
- Suitable for long-distance broadcasting due to their sky-mode propagation.
- Use omnidirectional antennas for signal transmission in all directions.

**Applications of Radio Waves:**

- Multicasting: One sender to many receivers (e.g., AM/FM radio, television, cordless phones, paging).

**2. Microwaves**

- Electromagnetic waves with frequencies from 1 GHz to 300 GHz.
- Unidirectional, line-of-sight propagation.

**Applications of Microwaves:**

- Unicast communication: One-to-one communication (e.g., cellular phones, satellite networks, wireless LANs).

**3. Infrared**

- Electromagnetic waves with frequencies ranging from 300 GHz to 400 THz.
- Used for short-range communication due to line-of-sight propagation.

**Applications of Infrared:**

- High-data-rate digital data transmission.

<img width="700" alt="ping" src="https://computernetworkingsimplified.wordpress.com/wp-content/uploads/2013/08/wiredcables.jpg">
