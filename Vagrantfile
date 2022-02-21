# -*- mode: ruby -*-
# vi: set ft=ruby :

# All Vagrant configuration is done below. The "2" in Vagrant.configure
# configures the configuration version (we support older styles for
# backwards compatibility). Please don't change it unless you know what
# you're doing.
Vagrant.configure("2") do |config|
  config.vm.box_check_update = false
  config.ssh.forward_agent = true
  config.ssh.forward_x11 = true
  config.vm.define "simutorino"
  config.vm.provision "shell", path: "provision.sh", privileged: false
  config.vm.provider "virtualbox" do |vb|
    vb.customize ["modifyvm", :id, "--usb", "on"]
    vb.customize ["modifyvm", :id, "--usbehci", "off"]
    vb.cpus = 2
    vb.memory = 4096
    vb.name = "simutorino"
  end
  config.vm.box = "ubuntu/focal64"
  config.vm.hostname = "simutorino"
end