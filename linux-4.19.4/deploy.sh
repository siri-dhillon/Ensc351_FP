SUFFIX="-jaime"
set -e
make
make modules_install
cp arch/x86_64/boot/bzImage /boot/vmlinuz-linux$SUFFIX

sed s/linux/linux$SUFFIX/g \
	</etc/mkinitcpio.d/linux.preset \
	>/etc/mkinitcpio.d/linux$SUFFIX.preset
mkinitcpio -p linux$SUFFIX

grub-mkconfig -o /boot/grub/grub.cfg
