# 学号:2020217793 姓名：洪祎麟
a, b = eval(input("请输入两个正整数"))
c = [i for i in range(a,b+1) if 0 not in [i%d for d in range(2,int(i**0.5)+1)]]  #运用列表推导式求出a,b之间的所有素数
print(c)
