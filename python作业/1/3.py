#学号：2020217793 姓名：洪祎麟
a=input("请输入任意一个n位整数")

#第一种方法：
b=list(a)
c=b[::-1]
print(list(map(int,c)))

#第二种方法：
print("".join(list(reversed(b))))

#第三种方法：
d=0
e=eval(a)
while(e/10):
    d=10*d+e%10
    e=e//10
print(d)