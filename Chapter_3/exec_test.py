x = 99
print('x before exec call: ', x)
exec(open('script1.py').read())
print('x after exec call: ', x)
