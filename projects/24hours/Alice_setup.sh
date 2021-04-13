ip link set wg0 down
ip link delete wg0
ip link add wg0 type wireguard
ip addr add 10.0.0.2/24 dev wg0
wg set wg0 private-key ./Alice_privkey listen-port 50000
ip link set wg0 up

wg set wg0 peer RuJp0QUZ0jtCwmKGeQex9qP0TeZfFW4FqHfj0f5ipSs=  allowed-ips 10.0.0.1/32 endpoint 192.168.18.5:50000
echo 'module wireguard +p' | sudo tee /sys/kernel/debug/dynamic_debug/control