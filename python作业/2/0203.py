#学号：2020217793 姓名：洪祎麟
n=input("请输入一个任意长度的整数")
n=eval(n)
lst1=list()
result=0
while(n):
    lst1.append(n%10)
    n=n//10
for i in lst1:
    result=10*result+i
print("这个整数的逆序为",result)