#学号：2020217793 姓名：洪祎麟
import random,string
lst1=list(string.ascii_letters)
lst2=random.sample(lst1,30)
lst3=list()
for i in lst2:
    lst3.append(ord(i))
dict1=dict(zip(lst2,lst3))
print(dict1)
