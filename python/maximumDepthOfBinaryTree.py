from TreeNode import TreeNode, ConstructTree

constructor = ConstructTree()
a = [1,'#',3,4,5]
a = []
t = constructor.construct(a) 
#print t.right.right.left.x

class Solution:
	def maxDepth(self, root): 
		if root == None:
			return 0
		else: 
			maxHeight = 1
			tl = []
			tl.insert(0, {"node": root, "height": 1})
			while len(tl) > 0:
				current = tl.pop()
				currentHeight = current["height"]
				if current["node"].left == None and current["node"].right == None:
					if maxHeight < current["height"]:
						maxHeight = current["height"]
				if current["node"].left != None:
					tl.insert(0, {"node": current["node"].left, "height": currentHeight+1})
				if current["node"].right != None:
					tl.insert(0, {"node": current["node"].right, "height": currentHeight+1})
		return maxHeight 

sl = Solution()
print sl.maxDepth(t)
