def to_power(base, exponent):
    result = str(base**exponent);
    if (len(result) > 10):
        result = result[:10]+'e+'+str((len(result) - 1));
    return (result);

print("The result of 2^100 is: "+"{:.2f}".format(2 ** 100)[:5]+"e+30");
num = 5
exp = 100
print(f'The result of {num}^{exp} is: {str(to_power(num, exp))}');

