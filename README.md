# BugKillers

## Contributors
@lkwh12
@sjslush
@yh0203kim


## Ground rules
	1. 정시 퇴근 및 퇴근 이후 찾지 않기
	2. 감정적으로 리뷰하지 않으며, 긍정적인 단어로 리뷰하기
	3. 들어온 코드 리뷰는 피드백을 빠르고 상세하게 친절하게 진행 (워킹아워라면 1시간내)
	4. 빠른 리뷰 사이클을 통해 기능 추가 후 리팩토링 진행 (한 번에 완벽하려고 하지 않기)
	5. 코드 리뷰는 Ping-Pong 3번 이상 치지 않기 (피드백 반영 후 개선되면 승인)
	6. Code Review에 대해 항상 오픈 마인드로 참여
	7. 온라인일지라도, 출퇴근시 서로 인사해주기
	8. 커밋에 의도를 명확하게 표현하기 (내 코드를 남이 바로 이해할 것이라고 생각하지 말기)

----

## 팀프로젝트 진행

### 1. Coding Style
	Google C++ coding style
	-> Google C++ coding style checker(cpplint)
	ref. link : https://pros2.tistory.com/136

### 2. Naming Rule

### 3. Commit Message Rule
	feature : 새로운 기능 추가
	fix : 버그 수정
	docs : 문서 수정
	test : 테스트 코드 추가
	refactor : 코드 리팩토링
	style : 코드 의미에 영향을 주지 않는 변경사항
	예시 [fix] ~~ 버그 수정
		
### 4. Branch Rule
	Main Branch를 두고 개인 별 Develop Branch를 만들어 수정 진행
	PR을 통해 Main Branch에 Merge 진행(Merge and Squash, Merge and Rebase)
