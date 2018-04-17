## Homework 7 Report

### P1

To build the member graph, my solution was to check each member and check which groups they were part of. Within the group, the other members of that group was then checked, and if this member was not already added as a connection, they would be added as a connected member. The time complexity would be O(M*G*K). There is a for loop for each parameter we are checking. We iterate through all the members M, then through all the groups G the member is a part of, then through all the members K in that group.

### P2
WITH PATH: 
Time to find path to member 0.488885
Maximum resident set size (kbytes): 126932

WITHOUT PATH: 
Time to find path to member 0.442494
Maximum resident set size (kbytes): 126944

Difference: 12 kbytes

### P3
WITH PATH:
Time to find path to member 0.0139782
Maximum resident set size (kbytes): 126876

WITHOUT PATH:
Time to find path to member 0.00953305
Maximum resident set size (kbytes): 126912

Difference: 36 kbytes

IDDFS is much faster than BFS in this case. BFS is good for finding the shortest path. IDDFS is good for connectivity problems involving cyclical graphs.





