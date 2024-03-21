
######## Find common elements between three lists ########
list1=(1 2 3 4 5)
list2=(3 4 5 6 7 1)
list3=(5 6 7 8 9 1)

for element in "${list1[@]}";do
    if [[ "${list2[@]}" =~ "$element" && "${list3[@]}" =~ "$element" ]]; then
        echo "The element $element is common between all three lists"
    fi
done
##########################################################



############ Print Even Numbers less than 237 ############

mainlist=(1 2 3 4 5 6 7 200 201 245 222 239 400 20202)

for element in "${mainlist[@]}";do
    if [[ "$element" -lt 238 && "$element"%2 -eq 0 ]];then
        echo "$element"
    fi
done

##########################################################
