#学号：2020217793 姓名：洪祎麟
lst1=eval(input("请输入若干自然数构成的列表"))
def isodd(n):
    if(n%2):
        return 1
    else:
        return
lst2=list(filter(isodd,lst1))
print("奇数组成的新列表为",lst2)