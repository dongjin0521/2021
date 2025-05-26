
---

## 🚀 실행 방법 (Google Colab 기준)

1. 필수 패키지 설치
    ```bash
    !pip install fastapi[all] ultralytics opencv-python pyngrok
    ```

2. YOLOv8 모델 로드
    ```python
    from ultralytics import YOLO
    model = YOLO("yolov8n.pt")
    ```

3. ngrok 설정 및 FastAPI 서버 실행
    ```python
    from pyngrok import ngrok
    ngrok.set_auth_token("YOUR_TOKEN")
    public_url = ngrok.connect(8000)
    
    import uvicorn
    uvicorn.run("app:app", host="0.0.0.0", port=8000)
    ```

4. 웹 페이지 접속
    ```
    브라우저에서 ngrok이 생성한 URL에 접속
    ```

---

## ⚙️ 주요 기능

- ✅ YOLOv8 기반 객체 탐지 (Anchor-free 구조, C2f 모듈 적용)
- ✅ 웹캠 입력 → 실시간 WebSocket 전송 → 추론 결과 반환
- ✅ 웹캠 화면에 Bounding Box 및 클래스명 렌더링
- ✅ FPS 30에 근접한 비동기 처리
- ✅ GPU 메모리 관리 최적화 및 OOM 방지

---

## 🧠 학습한 내용 및 인사이트

- **YOLOv8 구조** 및 추론 파이프라인의 이해
- **WebRTC + WebSocket** 조합을 통한 실시간 시스템 설계
- **Google Colab 리소스 제약 극복** 및 ngrok 연결 유지 관리
- 실시간 AI 웹서비스의 **실무 적용 가능성 체감**

---

## 🛠 향후 개선 사항

| 개선 영역        | 개선 방안                                       |
|------------------|------------------------------------------------|
| 스트리밍 성능     | 4K 해상도 지원, 프레임 전송 최적화             |
| 기능 확장        | 탐지 결과 저장 (이미지/영상), 통계 분석 기능   |
| 사용자 경험      | 반응형 UI, 모바일 최적화, 시각화 고도화        |
| 인프라 확장성    | AWS, Azure로의 이식, 다중 사용자 지원          |

---

## 📎 참고

- 📄 발표 자료 PDF: [`yolov8_temp.pdf`](./yolov8_temp.pdf)
- 💻 실습 링크: [Colab 프로젝트 링크](https://colab.research.google.com/drive/1lW4j0t5oPZYiinn2NAY3pN3BiDztrfVg?usp=sharing)

---

## 🙋‍♂️ 작성자

**이동진 (컴퓨터학부, 2025)**  
GitHub: [@dongjin0521](https://github.com/dongjin0521)

