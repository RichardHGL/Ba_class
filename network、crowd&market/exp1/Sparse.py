import numpy as np
from scipy.sparse import csr_matrix

row = []
col = []
data = []
row1 = []
col1 = []
data1 = []

train = open("trainset_2008.txt",'rb')
test  = open("testset_2008.txt",'rb')
for each_line in train:
#		try:
	(a1,a2,a3) = each_line.split(" ")
	row.append(int(a1))	
	col.append(int(a2))
	data.append(int(a3))
	
for each_line in test:
#		try:
	(a1,a2,a3) = each_line.split(" ")
	row1.append(int(a1))
	col1.append(int(a2))
	data1.append(int(a3))
'''
row_ = np.array(row)
row1_ = np.array(row1)
col_ = np.array(col)
col1_ = np.array(col1)
data_ = np.array(data)
data1_ = np.array(data1)
'''	
mt = csr_matrix((data,(row,col)),shape=(1712431,1712431))
mt2 = csr_matrix((data1,(row1,col1)),shape=(1712431,1712431))
mt3 = mt * mt

train.close()
test.close()


num = dict()
acu = dict()

(l1,l2) = mt3.nonzero()
for i in range(len(l1)):
	if i%1000 == 0:
		print i
	if mt3[l1[i],l2[i]] in num:
		num[mt3[l1[i],l2[i]]] += 1;
	else:
		num[mt3[l1[i],l2[i]]] = 1;
	if(mt[l1[i],l2[i]] == 0 and mt2[l1[i],l2[i]] != 0):
		if mt3[l1[i],l2[i]] in acu:
			acu[mt3[l1[i],l2[i]]] += 1;
		else:
			acu[mt3[l1[i],l2[i]]] = 1;

output = open("result_2008.txt","wb")

for i in num:
	output.write(str(i) +" ")
	output.write(str(num[i]) +" ")
	if i in acu:
		output.write(str(acu[i]) + "\n")
	else:
		output.write("0\n")
output.close()
''''
mt3 = mt1 * mt1
n = mt1.shape[0]
for i in range(n):
	for j in range(i,n):
		if mt1[i,j] == 0:
			if mt3[i,j] in
'''