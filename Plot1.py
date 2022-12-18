import matplotlib.pyplot as plt
heights1 = []
p1_val = []
heights2 = []
p2_val = []
heights3 = []
p3_val = []

with open('fork1.txt', 'r') as f:    
    for line in f:
        l = line.split()
        nums = l[0]
        heights1.append( float(l[1]))
        p1_val.append("OTH_"+l[0])
with open('fork2.txt', 'r') as f:    
    for line in f:
        l = line.split()
        nums = l[0]
        heights2.append( float(l[1]))
        p2_val.append("RR_"+l[0])
with open('fork3.txt', 'r') as f:    
    for line in f:
        l = line.split()
        nums = l[0]
        heights3.append( float(l[1]))
        p3_val.append("FIFO_"+l[0])

fig,axis=plt.subplots(2,3)

# i=0
# for m in range(2):
#     for j in range(3):
#         y=[heights1[i],heights2[i],heights3[i]]
#         x=[p1_val[i],p2_val[i],p3_val[i]]
#         axis[m,j].bar(x,y)
#         plt.ylabel("Runtime")
y=[heights1[0],heights2[0],heights3[0]]
x=[p1_val[0],p2_val[0],p3_val[0]]
axis[0,0].bar(x,y)
y=[heights1[1],heights2[1],heights3[1]]
x=[p1_val[1],p2_val[1],p3_val[1]]
axis[0,1].bar(x,y)
y=[heights1[2],heights2[2],heights3[2]]
x=[p1_val[2],p2_val[2],p3_val[2]]
axis[0,2].bar(x,y)
y=[heights1[3],heights2[3],heights3[3]]
x=[p1_val[3],p2_val[3],p3_val[3]]
axis[1,0].bar(x,y)
y=[heights1[5],heights2[5],heights3[5]]
x=[p1_val[5],p2_val[5],p3_val[5]]
axis[1,1].bar(x,y)
y=[heights1[4],heights2[4],heights3[4]]
x=[p1_val[4],p2_val[4],p3_val[4]]
axis[1,2].bar(x,y)

        
plt.show()
plt.savefig('second.png')
    


    
