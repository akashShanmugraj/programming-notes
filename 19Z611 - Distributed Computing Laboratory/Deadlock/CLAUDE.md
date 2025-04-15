I'd be happy to help you understand these deadlock detection algorithms in distributed systems. Let's go through each one with pseudocode and intuition.

# 1. Centralized Deadlock Detection

**Intuition:**
In a centralized approach, one site (coordinator) is responsible for detecting deadlocks across the entire distributed system. Each site maintains its local wait-for graph (WFG) and periodically sends this information to the coordinator. The coordinator combines these local WFGs to form a global WFG and checks for cycles.

**Pseudocode:**

```
// At each site i:
function SiteProcess(i)
    maintain local_WFG[i]
    periodically:
        send local_WFG[i] to Coordinator
    on resource_request(Transaction T, Resource R):
        if R is locally available:
            grant R to T
        else:
            add edge T → holder(R) to local_WFG[i]
            send updated local_WFG[i] to Coordinator
    
// At the coordinator:
function CoordinatorProcess()
    initialize global_WFG as empty
    
    on receiving local_WFG[i] from site i:
        update global_WFG with local_WFG[i]
        if cycle_exists(global_WFG):
            select a victim transaction V
            initiate abort(V)
            notify all sites to update their local_WFGs
            remove V and its edges from global_WFG

function cycle_exists(graph)
    // Use DFS or similar algorithm to detect cycles
    return true if cycle found, false otherwise
```

# 2. Hierarchical Deadlock Detection

**Intuition:**
Sites are organized in a hierarchical tree structure. Deadlock detection occurs at multiple levels, with each controller responsible for detecting deadlocks within its subtree. If a controller can't detect a deadlock locally but suspects one, it escalates to its parent controller.

**Pseudocode:**

```
// For each controller at level i:
function ControllerProcess(i)
    initialize local_WFG
    
    on receiving local_WFG from child:
        merge with current local_WFG
    
    on local transaction T waiting for resource R held by transaction T' at another site:
        if T' is within my subtree:
            update local_WFG with edge T → T'
            if cycle_exists(local_WFG):
                select victim V and abort(V)
        else:
            forward wait information to parent controller
    
    periodically:
        if unresolved wait dependencies exist:
            send condensed_WFG to parent controller
    
    on receiving abort instruction from parent:
        execute abort and propagate to relevant children

// At the root controller:
function RootControllerProcess()
    initialize global_WFG
    
    on receiving condensed_WFGs from children:
        update global_WFG
        if cycle_exists(global_WFG):
            select victim V
            initiate abort(V)
            propagate abort to relevant child controllers
```

# 3. WFG-based Distributed Deadlock Detection

**Intuition:**
In this approach, there's no central coordinator. Each site maintains its own WFG and exchanges information with other sites as transactions wait for resources across sites. The key is that wait-dependency information propagates through the system until a cycle is detected or all dependencies are resolved.

**Pseudocode:**

```pseudocode
// At each site i:
function SiteProcess(i)
    initialize local_WFG[i]
    
    on transaction T requesting resource R held by transaction T':
        if T' is local:
            add edge T → T' to local_WFG[i]
            if cycle_exists(local_WFG[i]):
                select victim V and abort(V)
        else:
            // T' is at remote site j
            add edge T → T' to local_WFG[i]
            send wait_message(T, T') to site j
    
    on receiving wait_message(T, T') where T' is local:
        add edge T → T' to local_WFG[i]
        for each transaction U that T' waits for:
            if U is local:
                add edge T → U to local_WFG[i]
                if cycle_exists(local_WFG[i]):
                    select victim V and abort(V)
            else:
                // U is at remote site k
                send wait_message(T, U) to site k
    
    on transaction T releases resource R:
        remove all edges from local_WFG[i] where T is the source
        propagate this information to relevant sites
    
    on transaction T completes:
        remove T and all its edges from local_WFG[i]
        propagate this information to relevant sites

function cycle_exists(graph)
    // Use DFS or similar algorithm to detect cycles
    return true if cycle found, false otherwise

```

# 4. Probe-based Distributed Deadlock Detection

**Intuition:**
When a transaction waits for a resource, it initiates a "probe" message that traverses the wait-for dependencies. If the probe returns to the initiator, a deadlock is detected. This approach is often called the "edge-chasing" algorithm.

**Pseudocode:**

```pseudocode
// At each site i:
function SiteProcess(i)
    initialize wait_for_graph
    
    on transaction T waiting for resource R held by transaction T':
        if waiting_time > threshold:
            // Initiate probe
            init_probe(T, T', T)  // (initiator, current, first)
    
    on receiving probe(T_init, T_curr, T_first):
        if T_first is local and has an outgoing edge:
            // Process first node of the probe
            for each transaction U that T_first waits for:
                send probe(T_init, U, U) to site(U)
        else if T_curr is local:
            // Process intermediate node
            if T_curr == T_init:
                // Deadlock detected!
                initiate deadlock_resolution(T_init)
            else:
                for each transaction U that T_curr waits for:
                    send probe(T_init, U, T_first) to site(U)
        else:
            // Forward probe to site containing T_curr
            forward probe(T_init, T_curr, T_first) to site(T_curr)
    
    on deadlock_resolution(T):
        if T is local:
            abort T
            notify all relevant sites
        else:
            forward deadlock_resolution(T) to site(T)
    
    on transaction T completes or aborts:
        remove T and all its edges from wait_for_graph
        notify all relevant sites

function site(T)
    // Return the site ID where transaction T is located
    return site_id

```

## Key Differences and Trade-offs

1. **Centralized**:
   - Simple implementation
   - Single point of failure
   - Potential bottleneck at coordinator
   - High message complexity to maintain global state

2. **Hierarchical**:
   - More fault-tolerant than centralized
   - Reduces message overhead
   - Can detect deadlocks at different levels
   - More complex to implement and maintain

3. **WFG-based Distributed**:
   - No single point of failure
   - Potentially high message overhead
   - Each site maintains partial global state
   - Good for systems with mostly local resource access

4. **Probe-based Distributed**:
   - Low message overhead in absence of deadlocks
   - No need for global wait-for graph
   - Detection time can be longer
   - Works well in systems with frequent cross-site dependencies

Would you like me to elaborate on any of these algorithms or explain their implementation in a specific programming language?