function checkPrime() {
    local n=$1
    local i=2
    for ((i = 2; i * i <= n; i++)); do
        if ((n % i == 0)); then
            echo 0
            return
        fi
    done
    echo 1
}

echo -n "Enter number: "
read num

for ((i = 2; i < num; i++)); do
    isPrime="$(checkPrime $i)"
    if ((num % i == 0 && isPrime == 1)); then
        echo -n "$i "
    fi
done

echo ""
