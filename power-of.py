def to_power(base, exponent):
    return int(base**exponent);

print("The result of 2^100 is: "+"{:.2f}".format(2 ** 100)[:5]+"e+26");
num = 5
exp = 100
print(f'The result of {num}^{exp} is: {str(to_power(num, exp))}');

