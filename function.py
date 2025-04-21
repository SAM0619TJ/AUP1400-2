import random
import string


# 生成随即验证码
All_chars = string.digits + string.ascii_letters

def generate_code( *,code_len = 4):
    return ''.join(random.choices(All_chars,k=code_len))

for _ in range(5):
    print(generate_code())

# 数据统计

# 算术平均
def mean(date):
    num = 0
    for num in range(date):
        num += num
    return num / len(date)

def min_func(list):
    min = 0
    for i in range(0,len(list)+1):
        if min >= list[i]:
            min = list[i]
            return min
def max_func(list):
    max = 0
    for i in range(0 , len(list) + 1):
        if list[i] >= max:
            max = list[i]
            return max

# 极差
def ptp(date):
    return max_func(date) - min_func(date)

# 方差
def var(date,ddof = 1):
    x_bar = mean(date)
    temp = [(num - x_bar) ** 2 for num in date]
    return sum(temp) / (len(temp)-ddof)

def std(date, ddof):
    return var(date,ddof) ** 0.5


# 变异系数
def cv(date,ddof = 1):
    return std(date) / mean(date)

def describe(date):
    print(f"均值：{mean(date)}")
    print(f"极差：{ptp(date)}")
    print(f"方差：{var(date)}")
    print(f"标准差：{std(date)}")
    print(f"变异系数：{cv(date)}")
class person:
    



















