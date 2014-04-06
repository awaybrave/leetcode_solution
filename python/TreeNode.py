import pdb
class TreeNode:
	def __init__(self, x):
		self.x = x
		self.left = None
		self.right = None
class ConstructTree:
	def construct(self, treelist):
		l = len(treelist)
		# to avoid the out of range error
		treeNode = [None] * l
		for i in xrange(l):
			if treelist[i] != '#':
				treeNode[i] = TreeNode(treelist[i])
			else:
				treeNode[i] = None
		noneCount = 0
		#pdb.set_trace()
		for i in xrange(l):
			if treelist[i] != '#':
				lindex = (i-noneCount)*2+1
				rindex = (i-noneCount)*2+2
				if lindex < l:
					treeNode[i].left = treeNode[lindex]
				else:
					break
				if rindex < l:
					treeNode[i].right = treeNode[rindex]
				else:
					break
			else:
				noneCount = noneCount + 1

		if len(treeNode) == 0:
			return None
		else:
			return treeNode[0]
