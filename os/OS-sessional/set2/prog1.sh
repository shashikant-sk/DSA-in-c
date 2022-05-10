function print_in_reverse() {
    local s=$1
    local rev=$(echo $s | rev)
    echo $rev
}

arr=()

echo -n "Enter a string: "
read str

for i in $str; do
    arr+=($i)
done

echo ${#arr[@]}
for i in ${arr[@]}; do
    print_in_reverse $i
done
