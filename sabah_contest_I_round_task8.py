v = [[] for i in range(100)]

def addEdge(x, y):
	v[x].append(y)
	v[y].append(x)

n = int(input())
stack = []
input_buff = []
count_dict = {}

for i in range(n-1):
	p1,p2,d1,d2 = map(int, input().split())
	input_buff.append([p1,p2,d1,d2])
	count_dict.update( { (p1,p2): 0 } )

def printPath(stack):
	for i in range(len(stack)-1):
		p1 = stack[i]
		p2 = stack[i+1]
		
		if (p1,p2) in count_dict:
			count_dict[(p1,p2)]+=1
		if (p2,p1) in count_dict:
			count_dict[(p2,p1)]+=1
	
	#print(stack)
	#print(count_dict)

def DFS(vis, x, y, stack):
	stack.append(x)
	if (x == y):
		# print the path and return on
		# reaching the destination node
		printPath(stack)
		return
	vis[x] = True

	if (len(v[x]) > 0):
		for j in v[x]:
			
			# if the node is not visited
			if (vis[j] == False):
				DFS(vis, j, y, stack)
				
	stack.pop()

# A utility function to initialise
# visited for the node and call
# DFS function for a given vertex x.
def DFSCall(x, y, n, stack):
	
	# visited array
	vis = [0 for i in range(n + 1)]


	# DFS function call
	DFS(vis, x, y, stack)

# END OF GEEKSFORGEEKS CODE

for i in range(n-1):
	addEdge(input_buff[i][0],input_buff[i][1])	

# Function Call
for i in range(1,n):
	DFSCall(i, i+1, n, [])

res = 0
for p1,p2,d1,d2 in input_buff:
	k1 = d1*count_dict[(p1,p2)]
	k2 = d2
	k = min(k1,k2)
	res += k

print(res)






