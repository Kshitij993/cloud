import matplotlib.pyplot as plt
import numpy as np

fcfs_ct=[]
fcfs_tt=[]
fcfs_wt=[]
sjf_ct=[]
sjf_tt=[]
sjf_wt=[]
rr_ct=[]
rr_tt=[]
rr_wt=[]

with open("fcfs.txt","r") as fp:
	lines=fp.readlines()
	for line in lines:
		word=line.split()
		fcfs_wt.append(float(word[0]))
		fcfs_tt.append(float(word[1]))
		fcfs_ct.append(float(word[2]))

with open("sjf.txt","r") as fp:
	lines=fp.readlines()
	for line in lines:
		word=line.split()
		sjf_wt.append(float(word[0]))
		sjf_tt.append(float(word[1]))
		sjf_ct.append(float(word[2]))

with open("round-robin.txt","r") as fp:
	lines=fp.readlines()
	for line in lines:
		word=line.split()
		rr_wt.append(float(word[0]))
		rr_tt.append(float(word[1]))
		rr_ct.append(float(word[2]))

fcfs_ct=np.array(fcfs_ct)
fcfs_tt=np.array(fcfs_tt)
fcfs_wt=np.array(fcfs_wt)

sjf_ct=np.array(sjf_ct)
sjf_tt=np.array(sjf_tt)
sjf_wt=np.array(sjf_wt)

rr_ct=np.array(rr_ct)
rr_tt=np.array(rr_tt)
rr_wt=np.array(rr_wt)

x=[]
for i in range(1,1001):
	x.append(i)
x=np.array(x)

#print(len(rr_ct))
#print(len(x))
'''
plt.scatter(x,fcfs_ct,color='r')
plt.scatter(x,sjf_ct,color='g')
plt.scatter(x,rr_ct,color='b')
plt.legend(['FCFS','SJF','RR'])
plt.xlabel("Test cases")
plt.ylabel("Completion time")
plt.show()

plt.scatter(x,fcfs_tt,color='r')
plt.scatter(x,sjf_tt,color='g')
plt.scatter(x,rr_tt,color='b')
plt.legend(['FCFS','SJF','RR'])
plt.xlabel("Test cases")
plt.ylabel("Turn around time")
plt.show()

plt.scatter(x,fcfs_wt,color='r')
plt.scatter(x,sjf_wt,color='g')
plt.scatter(x,rr_wt,color='b')
plt.legend(['FCFS','SJF','RR'])
plt.xlabel("Test cases")
plt.ylabel("Waiting time")
plt.show()
'''
