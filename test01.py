# 人生重开模拟器
import sys
import time
import random
print("+-----------------------------------+")
print("|                                   |")
print("|       华友重开日  人物在少年         |")
print("|                                   |")
print("|       欢迎来到 人生重开模拟器        |")
print("+-----------------------------------+")

while True :
    print("请设定初始属性（可用总点数为 20 ）")
    face = int(input("设定 颜值（1-10）："))
    strong = int(input("设定 体质（1-10）："))
    iq = int(input("设定 智力（1-10）："))
    home = int(input("设定 家境（1-10）："))

    if(face < 0 or face > 10) :
        print("颜值设定有误")
        continue
    if(strong < 0 or strong > 10) :
        print("体质设定有误")
        continue
    if(iq < 0 or iq > 10) :
        print("智力设定有误")
        continue
    if(home < 0 or home > 10) :
        print("家境设定有误")
        continue
    if face + strong + iq + home  > 20 :
        print("设定的总点数超过了20，请重新设定")
        continue

    print("设定完成")
    print(f"当前属性，颜值：{face}，体质：{strong}智力：{iq}家境：{home}")
    break

# 设定性别
point = random.randint(1, 6)
if point % 2 == 0 :
    gender = 'girl'
    print("你是一个女孩")
else :
    gender = 'boy'
    print("你是一个男孩")

# 设定出生点
point = random.randint(1, 3)
if home >= 10 :
    print("你出生在皇都，你父母都是高官")
    home += 1
    face += 1
    iq += 1
elif 7 <= home <= 9 :
    if point == 1 :
        print("你出生在大城市，你父母都是公务员")
        face += 1
        iq += 1
    elif point == 2 :
        print("你出生在大城市，你父母都是高级医生")
        strong += 2
    else :
        print("你出生在大城市，你父母都是企业高管")
        home += 2
elif 5 <= home <= 6 :
    if point == 1 :
        print("你出生在了镇上，你父母是教师")
        iq += 1
    elif point == 2 :
        print("你出生在了镇上，你父母是普通医生")
        strong += 1
    else :
        print("你出生在了镇上，你父母是个体经营户")
        home += 1
else :
    if point == 1 :
        print("你出生在了农村，你父母是农民")
        strong += 1
        face -= 1
    elif point == 2 :
        print("你出生在了农村，你父母是普通打工者，很努力，很少顾得上你")
        iq -= 1
        home += 1
    else :
        print("你出生在了农村，你父母是无业游民")
        strong -= 1
        face += 1

print(f"当前属性，颜值：{face}，体质：{strong}智力：{iq}家境：{home}")
# 设置 1 - 10岁的事件

for age in range(1 ,11) :
    info = f"你今年{age}岁"
    point = random.randint(1, 4)
    if home < 0 :
        print("你家穷死了")
        print("游戏结束")
        sys.exit(0)
    if strong < 0 :
        print("身体太弱，一场病把你带走了")
        print("游戏结束")
        sys.exit(0)

    # 家境
    if gender == 'girl' and home <= 3 and point == 1 :
        info += "你家人重男轻女思想非常严重，你被抛弃了！"
        print(info)
        print("游戏结束")
        sys.exit(0)
    elif gender == 'gril' and point == 1 :
        info += "你父母很爱你"
        face += 1
    elif gender == 'boy' and point == 1 :
        info += "那年你生了一场大病"
        if home >= 7 :
            info += "好在家境好，没有造成任何影响，父母更注重身体健康了"
            strong += 1
        elif home >= 5 :
            info += "在父母精心照料下，恢复了健康，但对智力造成了影响"
            strong += 1
            iq -= 1
        else :
            info += "父母没精力管你，身体更差了"
            strong -= 1

    # 颜值
    if gender == 'girl' and point == 2 :
        if face >= 7 :
            info += "你长得很漂亮，所以很多人喜欢你，你越来越自信"
            iq += 1
        elif face >= 5 :
            info += "你长的一般，所以过的很平淡"
        else :
            info += "你长的不好看，所以用学习填补自己，但别人总说，导致你有点自卑"
            iq += 1
            strong -= 1
    elif gender == 'boy' and point == 2 :
        if face >= 7 :
            info += "你长的很帅，大家都喜欢你"
            face += 1
        elif face >= 5 :
            info += "你长的一般，所以过的很平淡"
        else :
            info += "你长的不好看，别人还经常说你，所以经常打架"
            strong += 1
            iq -= 1

    # 体质
    if gender == 'girl' and point == 3 :
        if strong >= 7 :
            if home >= 5 :
                info += "你父母发现你有跳舞天赋，开始培养"
                face += 1
                strong += 1
            else :
                info += "你父母发现你有跳舞天赋，但家境不好，选择了忽视"
        elif strong >= 5 :
            info += "父母发现了你运动天赋，父母慢慢让你了解运动"
            strong += 1
        else :
            info += "从小体弱多病，经常看病"
            home -= 1

        if gender == 'boy' and point == 3:
            if strong >= 7 :
                if home >= 5:
                    info += "你父母发现你有运动天赋，开始培养"
                    face += 1
                    strong += 1
                else:
                    info += "你父母发现你有运动天赋，但家境不好，选择了忽视"
            elif strong >= 5 :
                info += "你体质比同龄人强很多，你制霸了学校"
                face += 1
            else :
                info += "从小体弱多病，经常看病"
                home -= 1

    # 智力
    if iq >= 7 and point == 4:
        info += "你父母发现了你特别聪明，送进了当地最好的学校"
        iq += 1
        strong += 1
        face += 1
        home -= 1
    elif iq >= 5 and point == 4:
        info += "你很聪明，学习很好，靠自己，在学校排前几，父母很开心"
        home += 1
    else :
        info += "你学习不好，因此，父母经常吵架"
        home -= 1

    print("---------------------------------------")
    print(info)
    print(f"当前属性，颜值：{face}，体质：{strong}智力：{iq}家境：{home}")
    time.sleep(2)
