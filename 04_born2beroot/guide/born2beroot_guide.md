# Born2beRoot Guide
<br>

>This is a simple installation guide for the virtual machine proposed by the project.
<br>

### Part 01: Download Your Virtual Machine and Your OS (Operating System)
<br>

We will utilize **Oracle VirtualBox** software to set up our virtual machine, with **Debian** as the chosen **OS**. 

1. Download Oracle VirtualBox: www.virtualbox.org

2. Download Debian: www.debian.org/download
<br>

### Part 02: Install Your Virtual Machine
<br>

We are going to use the **Oracle VirtualBox** software in order to install our virtual machine and **Debian** as an **OS**. 

1. Open the Oracle VirtualBox, click on `Machine` ⇒ `New`

2. Name and operating system:

    - Name: `born2beroot`
    - Type: `Linux`
    - Version: `Debian (64-bit)`

3. Memory size:

    - Choose the recommended memory size: `1024MB`

4. Hard disk:

    - Create a virtual hard disk now
    - VDI (VirtualBox Disk Image)
    - Storage on physical hard disk: Dynamically allocated
    - File location and size: for this project, I chose `8GB` for the size
    - After that, your VM is created and is showing on the VM list

5. Change the Network:
    
    - Select the VM, click on `Settings`
    - First, go to `Network` and select Attached to `NAT` ⇒ `Advanced` ⇒ `Port Forwarding` ⇒ `Add`
    - Set `Host Port` and `Guest Port` to `4242`
    - Then, go back to `Network` and now select Attached to `Bridged Adapter` ⇒ `enp3s0f0`

6. Configure the VM:

    - Select the VM and click on `Start`
    - Select part-up disk: here you will find your file with your OS chosen: `debian-12.1.0-amd64-netinst.iso`
    - Select `Install` (without a graphic interface)
    - Select a language: `English`
    - Select country, territory or area: `other` ⇒ `South America` ⇒ `Brazil`
    - Configure locales: `United States en_US.UTF-8`
    - Configure the keyboard: `Brazilian`
    - Hostname: your `login+42`
    - Domain name: `blank`
    - Root password: should follow the rules
    - Full name for the new user: your `name`
    - Username for your account: your `login`
    - New user password: should follow the rules
    - Configure the clock: `São Paulo`
<br>

### Part 03: Partition Disks Configuration
<br>
    
1. Select `Manual` (to accomplish the first part of the bonus)

2. Select a partition to modify its settings ⇒ `SCST1 (0, 0, 0) (sda) - 10.7 GB ATA VBOX HARDDISK` (whole memory to be used) ⇒ Create a new empty partition table on this device: `Yes`
- Now you have a free space, select: `pri/log 10.7GB FREE SPACE`
- In this part you are going to create 2 partitions:
    - First: not encrypted, we use a physical memory to start the VM:
        - `Create a new partition` ⇒ `500MB` ⇒ `Primary` ⇒ `Beginning` ⇒ Use as `Ext4` ⇒ Mount point: `/boot` ⇒ `Done setting up the partition`
    - Second: encrypted, we will use a logical memory to the following `logical volumes` on the VM:
        - `Create a new partition` ⇒ `max` ⇒ `Logical` ⇒ Use as `Ext4` ⇒ Mount point: `blank`  ⇒ `Done setting up the partition`
        - `Configure encrypted volumes` ⇒ `Create encrypted volumes` ⇒ `/dev/sda5` ⇒ `Done setting up the partition` ⇒ `Finish` ⇒ `Yes`
- Once we have the `primary` and `logical` partitions created, we are going to start to configure the LVM:
    - Create a group: `Configure the Logical Volume Manager` ⇒ `Create Volume group` ⇒ group name: `LVMGroup` ⇒ `/dev/mapper/sda5_crypt`
    - Create logical volume: `Create Logical Volume` ⇒ `LVMGroup`
    - After creating all the logical volumes, you will need to change the `Use as` and `Mount points` on each one
    - Below we have all the data needed to create and set up the logical volumes:
        - name `root` ⇒ size `3.2GB (32.47%)` ⇒ Use as `Ext4` ⇒ Mount point `/`
        - name `swap` ⇒ size `747MB (7.47%)` ⇒ Use as `swap area`
        - name `home` ⇒ size `1.6GB (16.23%)` ⇒ Use as `Ext4` ⇒ Mount point `/home`
        - name `var` ⇒ size `974MB (9.74%)` ⇒ Use as `Ext4` ⇒ Mount point `/var`
        - name `srv` ⇒ size `974MB (9.74%)` ⇒ Use as `Ext4` ⇒ Mount point `/srv`
        - name `tmp` ⇒ size `974MB (9.74%)` ⇒ Use as `Ext4` ⇒ Mount point `/tmp`
        - name `var-log` ⇒ size `1.2GB (12.99%)` ⇒ Use as `Ext4` ⇒ Mount point `Enter manually` ⇒ `/var-log`
        - Select `Finish`
    - Write the changes to the disks: `Yes`
    - Scan extra installation media: `No`
    - Debian archive mirror country and Debian archive mirror: `Brazil` ⇒ `deb.debian.org`
    - HTTP proxy: `blank`
    - Choose software to install: `SSH server` and `standard system utilities`
    - Install the GRUB loader: `Yes` ⇒ `/dev/sda…`

### Part 04: Sudo Configuration
<br>

- Install sudo: `apt install sudo`
- Check the installation: `dpkg -l | grep sudo` or `apt search sudo`
- Configure sudo directory: `sudo mkdir /var/log/sudo`
- Edit sudo file: `sudo visudo`
    - Password tries: `Defaults	passwd_tries = 3`
    - Message if password goes wrong: `Defaults badpass_message = "Wrong Password, padawan!"` or `Defaults insults`
    - To salve all the sudo activities:
        - `Defaults logfile="/var/log/sudo/sudo.log"`
        - `Defaults log_input, log_output`
        - `Defaults iolog_dir="/var/log/sudo"`
    - TTY: `Defaults requiretty`
    - Define sudo local: `Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"`
- Add user to sudo group: `adduser <username> sudo`
- Delete user from sudo group: `deluser <username> sudo`
- Check sudo group: `getent group sudo`
- See the evaluation part:
    - authentication using `sudo` has to be limited to 3 attempts in the event of an incorrect password
    - a custom message of your choice has to be displayed if an error due to a wrong password occurs when using a `sudo`
    - each action using `sudo` has to be archived, both inputs and outputs. The log file has to be saved in the`/var/log/sudo/folder`
    - the TTY mode has to be enabled for security reasons
    - for security reasons too, the paths that can be used by sudo must be restricted
        - `/usr/local/sbin`, `/usr/local/bin`, `/usr/sbin`, `/usr/bin`, `/sbin`, `/bin`, `/snap/bin`

### Part 05: Users and Groups
<br>

    - Users that should exist: `root` and `yourlogin`
    - Check users:
    - Create user:
    - Delete user:
    - Groups that should exist: `user42` and `sudo`
    - Your user (`yourlogin`) has to belong to the `user42` and `sudo`
    - Check the list of groups:
    - Check specific group: `getent <groupname> group`
    - Create group:
    - Delete group:
    - Add user to group: `adduser <username> group`
    - Delete user from a group: `deluser <username> group`
    - groupadd evaluating?
    - change user: `su - user` (su: switch user)

### Part 06: UFW Firewall Configuration
<br>

    - Install UFW: `apt install ufw`
    - Check the installation: `dpkg -l | grep ufw`
    - Enable UFW: `ufw enable`
    - Allow port 4242: `ufw allow 4242`
    - Check the status: `ufw status`
    - For a bonus, add port 80: `ufw allow 80`

### Part 07: SSH Configuration
<br>

    - Install SSH server: `apt install openssh-server`
    - Check the installation: `dpkg -l | grep ssh`
    - Configuring SSH: `nano etc/ssh/sshd_config`
        - Change line 13 `#Port 22` to `Port 4242`
        - Change: `PermitRootLogin no`
        - Enable SSH: `ssh enable`
        - Check the changes: `systemctl status ssh` or `service ssh status`
    - Connect via SSH:
        - Check the IP/inet: `ifconfig` or `ip address`
        - Connecting `ssh <username>@<ip-address> -p 4242`
        - `logout`
    - After configuring the ssh, enable the ssh: `systemctl enable ssh` ⇒ check the status: `systemctl status ssh` ⇒ you may need to restart: `systemctl restart ssh`
    - An SSH service will be running on port 4242 only
    - It must not be possible to connect using SSH as root
    - Connection `inet`, `netmask` and `getaway`:
        - inet 10.12.200.174 netmask 255.255.0.0
        - getaway has the same value of the address/inet, but ending with 254.254 (example: 10.12.254.254)
        - those numbers can change, you can check with `ifconfig`
        - you can add the changes in `/etc/network/interfaces`
        - It is better to have “interfaces” `static`, but if you change your location, go back to `dhcp`, get the current addresses with `ifconfig`, then change “interfaces” and go back to `static`, and restart the the networking: `service networking —full-restart`
        - When you try to connect with `ssh`, put the current address: user@inet -p 4242

### Part 08: Password Policy
<br>
    
    - Edit the login.defs file: `nano /etc/login.defs`
        - Expire every 30 days: `PASS_MAX_DAYS 30`
        - Minimum 2 days before the modification: `PASS_MIN_DAYS 2`
        - Warning message 7 days before the password expire: `PASS_WARN_AGE 7`
    - Install lib for strong password policy: `apt install libpam-pwquality`
    - Check the installation: `dpkg -l | grep libpam-pwquality`
    - Edit the file: `nano /etc/pam.d/common-password`
        - On line 25, add the rules:  `password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`
    - After creat`ing` the password policies, check if it is working with the root user: `chage flags -W -M -m`

### Part 09:Cron and Monitoring Script
<br>
    
    - Create a file `monitoring.sh`
    - The script will display the information listed below on all terminals every 10 minutes at server startup.
        - The architecture of your operating system and its kernel version
        - The number of physical processors
        - The number of virtual processors
        - The current available RAM on your server and its utilization rate as a percentage
        - The currently available memory on your server and its utilization rate as a percentage
        - The current utilization rate of your processors as a percentage
        - The date and time of the last reboot
        - Whether LVM is active or not
        - The number of active connections
        - The number of users using the server
        - The IPv4 address of your server and its MAC (Media Access Control) address
        - The number of commands executed with the sudo program
    - Edit the cron file: `crontab -e`
        - Add this config: `/10 * * * * sh /path/to/script`
        - Boot time and other flags: `who -b` or `uptime -s`
        - How does cron work? See crontab.guru
        - `crontab -e` is the file where the execution rule of monitoring e sleep files is. They monitoring and sleep files are set up to work together (`&&`)
    - To fix some time issues, create a file `sleep.sh`

### Part 10: Submission
<br>
    
    - Get the signature of your VM: `cd VirtualBox VMS/vmname` ⇒ `sha1sum vmname.vdi`
    - `sha1sum` output example: `6e657c4619944be17df3c31faa030c25e43e40af`
    - The signature of your VM should be saved in a `signature.txt` file and turned in at the root of your Git repository

### Summary Installation List:
   
    - `apt install sudo`: sudo configuration
    - `apt install ufw`: uncomplicated firewall
    - `apt install openssh-server`: ssh configuration
    - `apt install net-tools`: for network with `Bridged Adapter`
    - `apt install libpam-pwquality`: password policies
    - `apt install bc`: basic calculator for the `sleep.sh`
    - `apt install sysstat`: mpstat used for the `monitoring.sh`
    - `apt install man`: Linux manual
