#学号：2020217793 姓名：洪祎麟
import random
lst1=list()
lst2=list()
lst3=list()
lst1=[i for i in range(1,100)]
lst2=[random.choice(lst1) for i in range(1,50)]
lst3=[i for i in (range(0,len(lst2))) if (lst2[i]==max(lst2))]
print("最大值下标为")
for i in lst3:
    print(i,end='\t')