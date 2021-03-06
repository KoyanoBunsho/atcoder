s = input()
s_odd = s[1::2]
s_even = s[0::2]
if s_odd == s_odd.upper() and s_even == s_even.lower():
    print("Yes")
else:
    print("No")