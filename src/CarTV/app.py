from backend.server import app, socketio
from backend.processors import image

if __name__ == '__main__':
    socketio.start_background_task(target=image.processor)
    socketio.run(app, debug=True)
