# Born2beRoot
<br>

>This project aims to introduce you to the wonderful world of virtualization. You will create your first machine in VirtualBox (or UTM if you can’t use VirtualBox) under specific instructions. Then, at the end of this project, you will be able to set up your own operating system while implementing strict rules.
<br>


## ✅ Mandatory part

This project consists of having you set up your first server by following specific rules:

- You must choose as an operating system either the latest stable version of Debian or the latest stable version of Rocky.
- You must create at least 2 encrypted partitions using LVM. Below is an example of the expected partitioning:

  <img src="Screenshot from 2023-10-10 16-57-08.png"/>

- A SSH service will be running on port 4242 only. For security reasons, it must not be possible to connect using SSH as root.
- You have to configure your operating system with the UFW (or firewalld for Rocky) firewall and thus leave only port 4242 open.
- The hostname of your virtual machine must be your login ending with 42 (e.g., wil42). You will have to modify this hostname during your evaluation.
- You have to implement a strong password policy:
  - To set up a strong password policy, you have to comply with the following requirements:
  - Your password has to expire every 30 days.
  - The minimum number of days allowed before the modification of a password will be set to 2.
  - The user has to receive a warning message 7 days before their password expires.
  - Your password must be at least 10 characters long. It must contain an uppercase letter, a lowercase letter, and a number. Also, it must not contain more than 3 consecutive identical characters.
  - The password must not include the name of the user.
  - The following rule does not apply to the root password: The password must have at least 7 characters that are not part of the former password.
  - Of course, your root password has to comply with this policy
- You have to install and configure sudo following strict rules. To set up a strong configuration for your sudo group, you have to comply with the following requirements:
  - Authentication using sudo has to be limited to 3 attempts in the event of an incorrect password.
  - A custom message of your choice has to be displayed if an error due to a wrong password occurs when using sudo.
  - Each action using sudo has to be archived, both inputs and outputs. The log file has to be saved in the /var/log/sudo/ folder.
  - The TTY mode has to be enabled for security reasons.
  - For security reasons too, the paths that can be used by sudo must be restricted.
  - Example: `/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/snap/bin`.
- In addition to the root user, a user with your login as username has to be present. This user has to belong to the user42 and sudo groups.
- Finally, you have to create a simple script called `monitoring.sh`. It must be developed in bash. At server startup, the script will display some information (listed below) on all terminals every 10 minutes. No error must be visible.
  - The architecture of your operating system and its kernel version.
  - The number of physical processors.
  - The number of virtual processors.
  - The current available RAM on your server and its utilization rate as a percentage.
  - The current available memory on your server and its utilization rate as a percentage.
  - The current utilization rate of your processors as a percentage.
  - The date and time of the last reboot.
  - Whether LVM is active or not.
  - The number of active connections.
  - The number of users using the server.
  - The IPv4 address of your server and its MAC (Media Access Control) address.
  - The number of commands executed with the sudo program.
  - This is an example of how the script is expected to work:
    
    <img src="Screenshot from 2023-10-10 17-13-19.png" />
    
<br>

## ⭐ Bonus

You don’t have to do all the bonuses. Considering this, I only implemented the first part.

- Set up partitions correctly so you get a structure similar to the one below:

  <img src="Screenshot from 2023-10-10 16-29-35.png"/>

- Set up a functional WordPress website with the following services: lighttpd, MariaDB, and PHP.
- Set up a service of your choice that you think is useful (NGINX / Apache2 excluded!).

