# Born2beRoot Guide
<br>

>This is a simple installation guide for the virtual machine proposed by the project.
<br>

### Part 01: Download Your Virtual Machine and Your OS (Operating System)

We will utilize **Oracle VirtualBox** software to set up our virtual machine, with **Debian** as the chosen **OS**. 

1. Download Oracle VirtualBox: www.virtualbox.org

2. Download Debian: www.debian.org/download
<br>

### Part 02: Install Your Virtual Machine

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
    
1. Select `Manual` (to accomplish the first part of the bonus)

2. Select a partition to modify its settings ⇒ `SCST1 (0, 0, 0) (sda) - 10.7 GB ATA VBOX HARDDISK` (whole memory to be used)
    
    - Create a new empty partition table on this device: `Yes`
    - Now we have a free space, select: `pri/log 10.7GB FREE SPACE`

3. In this part, we are going to create 2 partitions:
    
    - The first partition does not involve encryption, instead, we utilize physical memory to initiate the VM: `Create a new partition` ⇒ `500MB` ⇒ `Primary` ⇒ `Beginning` ⇒ Use as `Ext4` ⇒ Mount point: `/boot` ⇒ `Done setting up the partition`
    - The second partition is encrypted, we will utilize logical memory to access the following logical volumes on the VM: `Create a new partition` ⇒ `max` ⇒ `Logical` ⇒ Use as `Ext4` ⇒ Mount point: `blank`  ⇒ `Done setting up the partition`
    - After creating the second partition, we will proceed to configure the encrypted volumes: `Configure encrypted volumes` ⇒ `Create encrypted volumes` ⇒ `/dev/sda5` ⇒ `Done setting up the partition` ⇒ `Finish` ⇒ `Yes`

4. Once we have the `primary` and `logical` partitions created, we are going to start to configure the LVM:
    
    - Create a group: `Configure the Logical Volume Manager` ⇒ `Create Volume group` ⇒ group name: `LVMGroup` ⇒ `/dev/mapper/sda5_crypt`
    - Create logical volume: `Create Logical Volume` ⇒ `LVMGroup`
    - After creating all the logical volumes, it is necessary to adjust the 'Use as' and 'Mount points' for each one. Below, you will find all the necessary information to create and configure the logical volumes (based on 8GB):
      
        - name `root` ⇒ size `3.2GB (32.47%)` ⇒ Use as `Ext4` ⇒ Mount point `/`
        - name `swap` ⇒ size `747MB (7.47%)` ⇒ Use as `swap area`
        - name `home` ⇒ size `1.6GB (16.23%)` ⇒ Use as `Ext4` ⇒ Mount point `/home`
        - name `var` ⇒ size `974MB (9.74%)` ⇒ Use as `Ext4` ⇒ Mount point `/var`
        - name `srv` ⇒ size `974MB (9.74%)` ⇒ Use as `Ext4` ⇒ Mount point `/srv`
        - name `tmp` ⇒ size `974MB (9.74%)` ⇒ Use as `Ext4` ⇒ Mount point `/tmp`
        - name `var-log` ⇒ size `1.2GB (12.99%)` ⇒ Use as `Ext4` ⇒ Mount point `Enter manually` ⇒ `/var-log`
    
5. Finish the partitions:
    
    - Write the changes to the disks: `Yes`
    - Scan extra installation media: `No`
    - Debian archive mirror country and Debian archive mirror: `Brazil` ⇒ `deb.debian.org`
    - HTTP proxy: `blank`
    - Choose software to install: `SSH server` and `standard system utilities`
    - Install the GRUB loader: `Yes` ⇒ `/dev/sda…`
<br>

### Part 04: Sudo Configuration

1. Install sudo: `apt install sudo`

2. Check the installation: `dpkg -l | grep sudo` or `apt search sudo`

3. Configure sudo directory: `sudo mkdir /var/log/sudo`

4. Edit sudo file: `sudo visudo`
    
    - Password tries: `Defaults	passwd_tries = 3`
    - Message if password goes wrong: `Defaults badpass_message = "Wrong Password, padawan!"` or `Defaults insults`
    - To salve all the sudo activities:
        - `Defaults logfile="/var/log/sudo/sudo.log"`
        - `Defaults log_input, log_output`
        - `Defaults iolog_dir="/var/log/sudo"`
    - TTY: `Defaults requiretty`
    - Define sudo local: `Defaults secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin"`

5. Add user to sudo group: `adduser <username> sudo`

6. Delete user from sudo group: `deluser <username> sudo`

7. Check sudo group: `getent group sudo`

8. See the evaluation part:

    - Authentication using `sudo` has to be limited to 3 attempts in the event of an incorrect password
    - A custom message of your choice has to be displayed if an error due to a wrong password occurs when using a `sudo`
    - Each action using `sudo` has to be archived, both inputs and outputs. The log file has to be saved in the`/var/log/sudo/folder`
    - The TTY mode has to be enabled for security reasons
    - For security reasons too, the paths that can be used by sudo must be restricted: `/usr/local/sbin`, `/usr/local/bin`, `/usr/sbin`, `/usr/bin`, `/sbin`, `/bin`, `/snap/bin`
<br>

### Part 05: Users and Groups

1. Users that should exist: `root` and `yourlogin`

    - Create user: `adduser <username>`
    - Check users: `who` or `sudo cat /etc/passwd`
    - Delete user: `deluser --remove-homoe <username>`
    - Change user: `su - user` (su: switch user)

2. Groups that should exist: `user42` and `sudo`

    - Your user (`yourlogin`) has to belong to the `user42` and `sudo`
    - Check the list of groups: `getent group`
    - Check specific group: `getent <groupname> group`
    - Create group: `addgroup <groupname>`
    - Delete group: `groupdel <groupname>`
    - Add user to group: `adduser <username> group`
    - Delete user from a group: `deluser <username> group`
<br>

### Part 06: UFW Firewall Configuration

1. Install UFW: `apt install ufw`

    - Check the installation: `dpkg -l | grep ufw`

2. Enable UFW: `ufw enable`

3. Allow port 4242: `ufw allow 4242`
    
    - Check the status: `ufw status`
    - For a bonus, add port 80: `ufw allow 80`
<br>

### Part 07: SSH Configuration

1. Install SSH server: `apt install openssh-server`
    
    - Check the installation: `dpkg -l | grep ssh`

2. Configuring SSH: `nano etc/ssh/sshd_config`
    
    - Change line 13 `#Port 22` to `Port 4242`
    - Change: `PermitRootLogin no`
    - Enable SSH: `ssh enable` or `systemctl enable ssh`
    - Check the changes: `systemctl status ssh` or `service ssh status`
    - After configuring the and enable the SSH, you may need to restart: `systemctl restart ssh`

3. Connect via SSH:
    
    - Check the IP/inet: `ifconfig` or `ip address`
    - Connecting `ssh <username>@<ip-address> -p 4242`

4. Configuration for `inet`, `netmask` and `getaway`:
    
    - Here are some examples of `inet addresses: 10.12.200.174` with a `netmask of 255.255.0.0`
    - The `gateway` value is identical to the `address/inet`, except it ends with `254.254` (e.g., `10.12.254.254`)
    - These numbers may change, and you can verify them using the `ifconfig`
    - If you wish to make changes, you can update the configuration in the `/etc/network/interfaces`
    - You can have the connection set to `static` or `DHCP`
    - After change the connection, you may need to restart: `service networking —full-restart`
    - When attempting to connect via SSH, use the current IP address in the format user@inet -p `4242`
<br>

### Part 08: Password Policy
    
1. Edit the login.defs file: `nano /etc/login.defs`
    
    - Expire every 30 days: `PASS_MAX_DAYS 30`
    - Minimum 2 days before the modification: `PASS_MIN_DAYS 2`
    - Warning message 7 days before the password expire: `PASS_WARN_AGE 7`

2. Install lib for strong password policy: `apt install libpam-pwquality`

3. Check the installation: `dpkg -l | grep libpam-pwquality`

4. Edit the file: `nano /etc/pam.d/common-password`
    
    - On line 25, add the rules:  `password requisite pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root`

5. Once you've established the password policies, verify their functionality with the root user: `chage flags -W -M -m`
<br>

### Part 09: Cron and Monitoring Script
    
1. Create a file `monitoring.sh`

2. The script will display the information listed below on all terminals every 10 minutes at server startup.
    
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

3. Edit the cron file (where the execution rules for monitoring is defined).
   
    - Access the cron file: `crontab -e`
    - Add this configuration: `/10 * * * * sh /path/to/script`
    - For the system's boot time information: `who -b` or `uptime -s`
<br>

### Part 10: Submission
    
1. Get the signature of your VM: `cd VirtualBox VMS/vmname` ⇒ `sha1sum vmname.vdi`
    
    - `sha1sum` output example: `6e657c4619944be17df3c31faa030c25e43e40af`

2. The signature of your VM should be saved in a `signature.txt` file and turned in at the root of your Git repository
<br>

### Summary Installation List:

- Sudo: `apt install sudo`
- UFW: `apt install ufw`
- SSH: `apt install openssh-server`
- Network with `Bridged Adapter`: `apt install net-tools`
- Password policies: `apt install libpam-pwquality`
- Basic calculator for the `sleep.sh` (optional): `apt install bc`
- Linux Network Monitoring (mpstat) used for the `monitoring.sh`: `apt install sysstat`
- Linux manual: (optional): `apt install man`
- VIM editor (optional): `apt install vim`
