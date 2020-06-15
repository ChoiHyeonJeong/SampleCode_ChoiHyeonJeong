# SampleCode_Stage

* SampelCode_Stage 컨텐츠 기획
1.정의
 -> 전투를 진행 할 수 있는 컨텐츠
 
2. 구성단위
 2.1 Chapter 
  -> Stage의 가장 큰 구성단위
  -> Chpater의개수는 계속 늘어날 수 있다.
  -> 1개의 Chapter엔 스테이지가 여러 개 있을 수 있다.
 2.2 Stage
  -> Chpater의 하위 전투 집합체
  -> 기본 전투 단위
  -> Stage의 개수 또한 계속 늘어날 수 있다.
  
 3. 제약조건
  3.1 Chapter 오픈 조건
   -> 첫 Chapter일 때 자동 오픈
   -> 이전 Chpater 마지막 Stage 클리어
  3.2 Stage 오픈 조건
   -> 첫 Stage일 때 자동 오픈
   -> 해당 Chapter 오픈
   -> 이전 Stage 클리어
   
 4. 전투 입장 제한
  -> 재화 부족 시 입장 불가
  -> Chapter가 오픈 되지 않았을 때 입장 불가
  -> Stage가 오픈 되지 않았을 떄 입장 불가
 
 5. Stage 진행
  -> 1Chapter의 1Stage를 기준으로 스테이지를 하나씩 증가 시키면서 진행된다.
  -> 위 기준에 의거하여 최초 오픈 Stage는 1Chpater의 1Stage로 설정한다.
  -> Stage는 기본적으로 클리어 시 자동으로 다음 스테이지를 오픈 시켜준다.
  -> 다음 Stage에 대한 정보는 인덱스 룰에 의해 Stage 넘버를 하나씩 증가시켜준다.
  -> 다음 Stage가 없는 경우 다음 Chpater의 첫 번째 Stage를 오픈 시킨다.
  
 
  
 
 
 
 
 
 
 
 
 
 
