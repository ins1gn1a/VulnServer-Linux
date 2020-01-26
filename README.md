# VulnServer
[![CI Status](https://github.com/ins1gn1a/VulnServer-Linux/workflows/build/badge.svg)](https://github.com/ins1gn1a/VulnServer-Linux/actions) 
[![GitHub pull-requests](https://img.shields.io/github/issues-pr/ins1gn1a/VulnServer-Linux.svg)](https://GitHub.com/ins1gn1a/VulnServer-Linux/pulls/)
[![GitHub contributors](https://img.shields.io/github/contributors/ins1gn1a/VulnServer-Linux.svg)](https://GitHub.com/ins1gn1a/VulnServer-Linux/graphs/contributors/)
[![GitHub issues](https://img.shields.io/github/issues/ins1gn1a/vulnserver-linux)](https://github.com/ins1gn1a/vulnserver-linux/issues)
[![GitHub stars](https://img.shields.io/github/stars/ins1gn1a/vulnserver-linux)](https://github.com/ins1gn1a/vulnserver-linux/stargazers)
[![GitHub license](https://img.shields.io/github/license/ins1gn1a/vulnserver-linux)](https://github.com/ins1gn1a/VulnServer-Linux/blob/master/LICENSE)

This program should not be run on any production systems or networks as it is purposely vulnerable. I will not be held accountable for any usage of this program and you run this at your own risk.

## Compile
```
wget https://raw.githubusercontent.com/ins1gn1a/VulnServer-Linux/master/vuln.c
gcc vuln.c -o vuln -fno-stack-protector -z execstack -mpreferred-stack-boundary=2
```

## References
Inspiration from [Stephen Bradshaw's vulnserver](https://github.com/stephenbradshaw/vulnserver/)!
