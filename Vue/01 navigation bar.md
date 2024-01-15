네비게이션 가드

1. 전역가드
 - beforeEach
 - beforeResolve
 - afterEach
2. 라우트별 가드
 - beforeEnter
3. 컴포넌트 내부 가드
 - beforeRouteEnter
 - beforeRouteLeave
 - beforeRouteUpdate

beforeEach
- 이걸 사용해서 보호하기 이전에 전역에 등록해서 해당 라우트를 보호할 수 있음
- 네비가 트리거될때마다 가드가 작성순서데로 호출되기 전에 모든경우에 발생함
- 가드는 비동기식으로 실행가능함
- 네비는 모든 훅이 해결되기 전까지 보류 중으로 간주됨
- to : 대상 route 객체로 이동함(home)
- from : 현 route로 오기전 라우트
- next : 훅을 해결하기 위해 호출되야함
	액션은 next에 제공된 전달인자에 다렸음
- next() : 파이프라인의 다음훅으로 이동. 훅이 없을 경우 네비 승인됨
- next(false) : 현 네비중단. 브라우저 url변경되면 from 경로의 url로 재설정됨
- next(/) 다른 위치로 redirect 됨. 현재 네비 중단. 새 네비.
- next(error) next에 전달된 인자가 error 인스턴스면 탐색 중단. onError를 이용해서 등록된 콜백에 에러가 전달됨

