#学号：2020217793 姓名：洪祎麟
import random,string
lst2=list()
dict1=dict()
lst1=list(string.ascii_letters)
lst2=[random.choice(lst1) for i in range(1,500)]
for i in lst2:
      dict1[i]=lst2.count(i)
print(dict1)
