from collections import deque


class Clock:
    def __init__(self):
        self.time = 0
    
    def tick(self):
        self.time += 1
    
    def wtt(self): #what is the time?
        return self.time


class Graph:
    def __init__(self):
        self.nodes = {}

    def V(self):
        return self.nodes.keys()

    def size(self):
        return len(self.nodes)

    def adj(self, u):
        if u in self.nodes:
            return self.nodes[u]

    def insertNode(self, u):
        if u not in self.nodes:
            self.nodes[u] = {}

    def insertEdge(self, u, v, w = 0):
        self.insertNode(u)
        self.insertNode(v)
        self.nodes[u][v] = w


    def hasCycle(self):

        def hc_rec(G, u, time, dt, ft):
            time.tick()
            dt[u] = time.wtt()

            for v in G.adj(u):
                if dt[v] == 0:
                    if hc_rec(G, v, time, dt, ft):
                        return True
                elif dt[u] > dt[v] and ft[v] == 0:
                    return True
            
            time.tick()
            ft[u] = time
            return False

        def hc_wrapper(G):

            time = Clock()
            dt = {}
            ft = {}
            for n in G.V():
                dt[n] = 0
                ft[n] = 0
            
            for n in G.V():
                if dt[n] == 0:
                    if hc_rec(G, n, time, dt, ft):
                        return True
            return False
        
        return hc_wrapper(self)


class UGraph(Graph):
    def insertEdge(self, u, v, w = 0):
        super().insertEdge(u, v)
        self.nodes[v][u] = w

    def hasCycle(self):
        def hc_rec(G, u, p, visited):
            visited[u] = True
            for v in G.adj(u):
                if (v != p) and (v in visited):
                    return True
                elif hc_rec(G, v, u, visited):
                    return True
            return False

        def hc_wrapper(G):
            visited = {}
            for n in G.V():
                visited[n] = False

            for n in G.V():
                if not (n in visited):
                    if hc_rec(G, n, n, visited):
                        return True
            return False
        
        return hc_wrapper(self)

def bfs_template(G, source_node):

    # SETUP
    queue = deque()
    visited = {}

    visited[source_node] = True
    queue.append(source_node) # O(1)

    # Write your own code here (till while)

    while len(queue) > 0:
        node = queue.popleft() # O(1)

        for a in G.adj(node):
            if a not in visited:
                visited[a] = True
                queue.append(a)

                #write your own code here


def dfs_rec(G, n, visited):
    visited[n] = True

    for a in G.adj(n):
        if not visited[a]:
            dfs_rec(G, a, visited)

def dfs_template(G):
    visited = {}

    for n in G.V():
        if n not in visited:
            dfs_rec(G, n, visited)


def erdos(G, source_node):

    queue = deque()
    queue.append(source_node) # O(1)

    dist = {}
    for n in G.V():
        dist[n] = -1
    
    dist[source_node] = 0

    while len(queue) > 0:
        node = queue.popleft() # O(1)

        for a in G.adj(node):
            if dist[a] < 0:
                queue.append(a)

                dist[a] = dist[node] + 1
    
    return dist


g = UGraph()

g.insertEdge('a', 'b')
g.insertEdge('b', 'c')
g.insertEdge('c', 'a')

print(g.hasCycle())