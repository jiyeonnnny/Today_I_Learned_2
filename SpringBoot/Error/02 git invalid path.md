# [Git Error] git invalid path
문제 : clone이 안되는 상황   
원인 : clone하는 파일 이름에 특수 문자가 있어서
       윈도우 파일 시스템이 인식하지 못하는 파일이 있었던 것      
해결 : 명령어 2개 입력    
```
$ git config core.protectNTFS false
$ git checkout -f HEAD
```