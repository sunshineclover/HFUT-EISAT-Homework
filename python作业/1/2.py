#学号：2020217793 姓名：洪祎麟

#函数：abs() 求出一个数的绝对值 可迭代对象：数字
a=-1 #创建一个对象
print(abs(a)) #求出对象的绝对值

#函数：all() 判断成员元素是否都为true，如果是返回True，否则返回 False 可迭代对象：元组或列表
lst1=[1,2,3,a,True]    #创建一个列表
lst2=[0,1,a]          #创建一个列表
print(all(lst1), all(lst2),sep='\t')      #分别输出all()函数对两个列表对象的结果

#函数：any() 函数用于判断给定成员元素是否全部为 False，如果是则返回 False，如果有一个为 True，则返回 True 可迭代对象：元组或列表
print(any(lst1), any(lst2),sep='\t')      #分别输出any()函数对两个列表对象的结果

#函数：ascii() 返回任何对象（字符串，元组，列表等）的可读版本，将所有非 ascii 字符替换为转义字符。可迭代对象：字符串，元组，列表，数字，字典，集合
print(ascii(lst1), ascii(lst2),sep='\t')      #分别输出any()函数对两个列表对象的结果

#函数：bin() 返回一个整数 int 或者长整数 long int 的二进制表示。 可迭代对象：数字
print(bin(54),sep='\t') #输出二进制表示

#函数：bool() 用于将给定参数转换为布尔类型，如果没有参数，返回 False 可迭代对象：字符串，元组，列表，数字，字典，集合
print(bool(lst1),bool(1),sep='\t') #输出bool类型值

#函数：chr() 用一个范围在0～255的整数作参数，返回一个对应的字符。 可迭代对象：数字
print(chr(30)) #输出对应字符

#函数：complex()用于创建一个值为a+bj的复数或者转化一个字符串或数为复数。如果第一个参数为字符串，则不需要指定第二个参数 可迭代对象：数字，字符串
a=1 #赋值
b=2 #赋值
print(complex(a,b)) #输出转化后的复数

#函数：dict() 用于创建一个字典
print(dict(a='1',b='2'),sep='\t')  #用关键字创建字典
print(dict(),sep='\t') #创建一个空字典

#函数：dir() 函数不带参数时，返回当前范围内的变量、方法和定义的类型列表；带参数时，返回参数的属性、方法列表。
print(dir(dict()),dir(list),sep='\t')

#函数：divmod() 函数接收两个数字类型（非复数）参数，返回一个包含商和余数的元组(a // b, a % b)
print(divmod(10,2),sep='\t')

#enumerate() 函数用于将一个可遍历的数据对象(如列表、元组或字符串)组合为一个索引序列，同时列出数据和数据下标
print(list(enumerate(lst1)))

#eval() 函数用来执行一个字符串表达式，并返回表达式的值。
print(eval("123123"))

#exec()函数执行储存在字符串或文件中的Python语句,返回值永远为 None
print(exec("123123"))

#exit()函数可以终止Python程序。
#print(exit())

#filter() 函数用于过滤序列，过滤掉不符合条件的元素，返回由符合条件元素组成的新列表的迭代器
def iseven(n): #建立过滤条件函数 判断是否为偶数
    return n % 2 == 0
print(list(filter(iseven,lst1)))  #输出结果

#float() 函数用于将整数和字符串转换成浮点数
print(float("3.5"))

#format函数用于格式化字符串
print("{a},{b}".format(a='hello',b='world'))

#frozenset() 返回一个冻结的集合，冻结后集合不能再添加或删除任何元素
set1=frozenset('12345')
print(set1)

#globals函数用于返回全局变量的字典。
print(globals())

#help() 函数用于查看函数或模块用途的详细说明。
print(help(help))

#hex() 函数用于将10进制整数转换成16进制，以字符串形式表示
print(hex(50))

#id() 函数返回对象的地址
print(id(lst1))

#input()函数接受一个标准输入数据，返回为 string 类型
str1=input("请输入一个数")
print(str1)

#int() 函数用于将一个字符串或数字转换为整型
b=int("123456")
print(b)

#isinstance() 函数来判断一个对象是否是一个已知的类型
print(isinstance(b,int))

#iter() 函数用来生成迭代器，返回迭代器
print(iter(lst1))

#len() 函数返回对象长度
print(len(lst1))

#list() 函数用于将元组转换为列表
tuple1=(1,2,3,4)
print(list(tuple1))

#locals() 函数会以字典返回当前位置的全部局部变量
print(locals())

#map()函数会根据提供的函数对指定的序列做映射,返回迭代器
print(list(map(iseven,lst1)))

#max()函数求出最大值
print(max(lst1))

#min()函数求出最小值
print(min(lst1))

#oct() 函数将一个整数转换成8进制字符串
print(oct(10))

#open() 函数用于打开一个文件
open("2.py")

#ord()函数返回一个字符对应的 ASCII 数值，或者 Unicode 数值
print(ord('h'))

#pow() 函数返回 x 的 y 次方 的值
x=5
y=2
print(pow(x,y))

#print()函数用于打印输出
print('haha')

#range()函数可创建一个整数列表，返回迭代器
for i in range(1,5): #对于在(1,5)范围内的每个数
    print(i)    #进行输出

#reversed()函数将参数的对象反转，返回迭代器
print(list(reversed(lst1)))

#round()函数返回浮点数x的四舍五入值，第一个参数为浮点数x，第二个参数为保留的位数
print(round(3.1415926,2))

#set()函数创建一个无序不重复元素集合
print(set('123445'))

#slice()函数实现切片对象
print(lst1[slice(0,5,-1)])

#sorted()函数实现从小到大排序
print(sorted(lst1))

#str()函数将对象转化为适于人阅读的形式
print(str("abcdef"))

#sum()函数对序列进行求和
print(sum(lst1))

#tuple()函数将列表转换为元组
print(tuple(lst1))

#type()函数返回对象的类型
print(type(lst1))

#zip()函数用于将可迭代的对象作为参数，将对象中对应的元素打包成一个个元组，然后返回由这些元组组成的列表，返回迭代器
print(list(zip(range(1,5),range(6,10))))
