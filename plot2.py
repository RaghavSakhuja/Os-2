import matplotlib.pyplot as plt
heights1 = []
p1_val = []
heights2 = []
p2_val = []
heights3 = []
p3_val = []

with open('OTHER.txt', 'r') as f:    
    for line in f:
        l = line.split()
        nums = l[0]
        heights1.append( float(l[1]))
        p1_val.append("OTH_"+l[0])
with open('RR.txt', 'r') as f:    
    for line in f:
        l = line.split()
        nums = l[0]
        heights2.append( float(l[1]))
        p2_val.append("RR_"+l[0])
with open('FIFO.txt', 'r') as f:    
    for line in f:
        l = line.split()
        nums = l[0]
        heights3.append( float(l[1]))
        p3_val.append("FIFO_"+l[0])

for i in range(len(heights1)):
        y=[heights1[i],heights2[i],heights3[i]]
        x=[p1_val[i],p2_val[i],p3_val[i]]
        # axis[m,j].bar(x,y)
        plt.bar(x,y)
        plt.ylabel("Runtime")
        plt.savefig(str(i)+".png")
        plt.close()


    
