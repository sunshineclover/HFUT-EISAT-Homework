#学号：2020217793 姓名：洪祎麟
import random
from collections import Counter
lst = [random.randint(0,1000) for i in range(100000) ]  #生成100000个范围在（0,1000）的数


#方法一：
result1 = {}     #准备存放入字典中
for i in lst:
    result1[i] = result1.get(i, 0) + 1   #统计每个数出现的次数

#方法二
result2 = {}
set2 =set(lst)                        #通过集合转换去重，便于下一步进行统计具体出现次数
for item in set2:
    result2[item] = lst.count(item)   #统计每个数出现的次数


b=Counter(result1)      #方案一
print(b.most_common(10)) #此为输出出现次数最多的前10个元素
print(b.most_common()[:-11:-1])
d=Counter(result2)          #方案二
print(d.most_common(10)) #此为输出出现次数最多的前10个元素
print(d.most_common()[:-11:-1])  # 取出计数最少的10个元素