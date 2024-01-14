# websocket 통신
- 클라이언트와 서버와의 통신

<br>
<br>
<br>

## 웹 소켓이란
- HTTP통신을 이용하면 클라리언트에서 서버로 요청을 보내야,
  서버에서 응답할 수 잇음
- 서버에서 요청을 받지 못하면 클라이언트랑 소통안됨
- 이런 문제를 해결하기 위해서,
  양방향으로 통신할 수 있는 웹소켓 통신 개발함

- 채팅, 문의, 알림, 트레이딩과 같은 **실시간** 키워드가 필요한
  기능들을 HTTP통신으로 구현할 수 없음
- 이런 기능은 소켓 통신으로 구현해야함

```js
let socket = new WebSocket("ws://chanstory.dev");
```
- http, https 프로토콜과 다르게 ws, wss 프로토콜을 사용함
- ws, wss 차이는 http, https처럼 보안과 신뢰성 차이임

<br>
<br>
<br>

## 웹소켓 연결 과정
- 핸드쉐이크 과정이 필요함
  핸드쉐이크 : 브라우저에서 소켓 통신을 이용하기 위해
              소켓 통신이 가능한지 확인하는 과정임

### 핸드 쉐이크 과정
1. 브라우저에서 HTTP통신을 이용해 서버에 소켓 통신 가능한지 요청을 보냄
   이때, 헤더에 소켓을 사용하기 위한 connection, websocket, upgrade에 관한 정보를 함께 전송함
    ```
    GET /chat
    Host: https://chanstory.dev
    Origin: https://chanstory.dev
    Connection: Upgrade
    Upgrade: websocket
    Sec-WebSocket-Key: ...
    Sec-WebSocket-Version: 13
    ```
2. 서버에서 웹소켓통신이 가능하면, 서버에서 웹 소켓 통신이가능하다는 101상태 응답을 보냄
   이때 서버에서 클라이언트로부터 받은 'Sec-WebSocket-Key'키 값에 문자를 더함으로써 암호화하여
   'Sec-WebSocket-Accept'로 클라리언트한테 응답함
   ```
   101 Switching Protocols
   Upgrade: websocket
   Connection: Upgrade
   Sec-WebSocket-Accept: ...
   ```
3. 이후 ws, wss 프로토콜로 양방향 통신을 진행함(서버랑 클라이언트)

<br>
<br>
<br>

## 웹소켓 활용
잘안됨
1. modul not found 
    => express not found => https://nicgoon.tistory.com/234
    => ws not found => https://nicgoon.tistory.com/235
    => 그다음 해당 html 실행됨 => localhost:3000
2. 다음 문제
    => html 어떻게 연결하는지 모르겠음
    => https://nicgoon.tistory.com/235
    => 설명이 부족한건지 이해를 못한건지 둘다인건지
    => 다음 모듈 http 서버에 연결해준다는데 이게 뭔말일까
    => express같은 경우 listen을 통해 만든 서버, http의 경우
       createServer 메서드로 만들어진 서버
       /bin/www 파일에 server객체가 정의되어 있을 거래 => 정의되어 있음
       적당한 위체에 아래같이 웹소켓을 연결해라
       => 적당한 위치에 코드 추가
    ```js
    const webSocket = require("../routes/webSocket");
    webSocket(server);
    ```
3. 다음 문제
npm start 실행이 안됨
```js
app.set('port', port);
```

```
error 내용
TypeError: app.set is not a function
app.js file에 set function이 없다는 뜻
```
```
여기서 내 생각

아니..app.js 어떻게 구현함?
난 걍 tistory에 있는 대로만 작성했는데 안됨...하...답답하네
```

    