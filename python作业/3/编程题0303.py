#学号：2020217793 姓名：洪祎麟
import string
a=list(string.ascii_letters)  #此为所有的大小写字母
b=[ord(i) for i in a]       #此为所有的大小写字母对应的ascii码
c=dict(zip(a,b))            #此为打包后的结果

print(c)