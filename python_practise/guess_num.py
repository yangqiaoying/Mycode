#!/usr/bin/env python
#coding=utf-8

import random

secret = random.randint(1,100)#生成的随机数1<=secret<=100

guess = 0
tries = 0

print u"你好，请你给出一个1-100的数字，试下你的运气如何？你只有六次机会哦！"

while guess != secret and tries < 6:
    print u"请给出你猜的数字:"
    guess_str = raw_input()

    if not str.strip(guess_str):
        print u"输入不能为空!"
    else:
        try:
            g = int(guess_str)
            if g == secret:
                print u"哇哦！恭喜你猜中咯！"
                break
            elif g < secret:
                print str(g),u"太小啦！你是猪吗？"
            else:
                print str(g),u"太大咯！你是猪吗？"
            tries += 1
        except ValueError:
            print u"不能输入字符串！"
else:
    print u"都猜了6次啦！小笨蛋^^"
    print u"姐姐告诉你哦，这个数字是：",str(secret)
