heroStats()
counter = 2
while(counter > 0)
do
    counter = counter - 1
    actionValue =  math.random(10)
    if (actionValue <= 5)
    then hp = battle(math.random(50),math.random(5))
        if (hp <= 0) 
        then return 
        end
    elseif (actionValue > 5 and actionValue <= 9)
        then rest()
    else bless()
    end
end