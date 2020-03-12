import cs50

s = cs50.get_string()
# Objects have built in functionality.
# String is no longer just a address a byte of memory
# "hello, word {}" is an object of type str
# Böyle olunca python içerisinde örneğin bir method olan format stringler'le beraber geliyor.
# Tıpkı cs50 objesinin get_string metoduna sahip olması gibi.
print("hello, {}".format(s))