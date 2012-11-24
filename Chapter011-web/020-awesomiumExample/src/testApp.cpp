#include "testApp.h"

/*
 OSX users:  You'll need to put this into project settings > Build Phases > Run Script
 It will copy the Awesomium.framework into the application bundle.
 cp -r "$TARGET_BUILD_DIR/../Awesomium.framework" "$TARGET_BUILD_DIR/$PRODUCT_NAME.app/Contents/Frameworks/"
 */

//--------------------------------------------------------------
void testApp::setup(){
    
    webTex.allocate(WIDTH, HEIGHT, GL_RGBA);
    

    // Disable scrollbars via the WebCoreConfig
    Awesomium::WebCoreConfig config;
    //config.setCustomCSS("::-webkit-scrollbar { display: none; }");
    
	// Create our WebCore singleton with the default options
	webCore = new Awesomium::WebCore(config);
	
	// Create a new WebView instance with a certain width and height, using the
	// WebCore we just created
	webView = webCore->createWebView(WIDTH, HEIGHT);
	
	// Load a certain URL into our WebView instance
	webView->loadURL("http://www.google.com");
    
	webView->focus();
}

//--------------------------------------------------------------
void testApp::exit(){
    // Destroy our WebView instance
	webView->destroy();
	delete webCore;
}

//--------------------------------------------------------------
void testApp::update(){
    
    webCore->update();
    
    // Call our display func when the WebView needs rendering
	if(webView->isDirty())
    {
        const Awesomium::RenderBuffer* renderBuffer = webView->render();
        if(renderBuffer) {
            webTex.loadData(renderBuffer->buffer, WIDTH, HEIGHT, GL_BGRA);
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    
    ofSetColor(255);
	webTex.draw(0, 0);

    if(webView->isLoadingPage()) {
        ofSetColor(0);
        ofDrawBitmapString("Loading...", 10, ofGetHeight()-20);
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

    switch(key)
	{
        case 8: case 127:
            injectKey(Awesomium::KeyCodes::AK_BACK);
            return;
        case 9:
            injectKey(Awesomium::KeyCodes::AK_TAB);
            return;
        case OF_KEY_LEFT:
            injectKey(Awesomium::KeyCodes::AK_LEFT);
            return;
        case OF_KEY_UP:
            injectKey(Awesomium::KeyCodes::AK_UP);
            return;
        case OF_KEY_RIGHT:
            injectKey(Awesomium::KeyCodes::AK_RIGHT);
            return;
        case OF_KEY_DOWN:
            injectKey(Awesomium::KeyCodes::AK_DOWN);
            return;
        case OF_KEY_PAGE_UP:
            injectKey(Awesomium::KeyCodes::AK_PRIOR);
            return;
        case OF_KEY_PAGE_DOWN:
            injectKey(Awesomium::KeyCodes::AK_NEXT);
            return;
        case OF_KEY_HOME:
            injectKey(Awesomium::KeyCodes::AK_HOME);
            return;
        case OF_KEY_END:
            injectKey(Awesomium::KeyCodes::AK_END);
            return;
	}
    
	Awesomium::WebKeyboardEvent keyEvent;
	keyEvent.text[0] = key;
	keyEvent.unmodifiedText[0] = key;
	keyEvent.type = Awesomium::WebKeyboardEvent::TYPE_CHAR;
	keyEvent.virtualKeyCode = key;
	keyEvent.nativeKeyCode = key;
	webView->injectKeyboardEvent(keyEvent);
}

//--------------------------------------------------------------
void testApp::injectKey(int keyCode)
{
	Awesomium::WebKeyboardEvent keyEvent;
    
	char* buf = new char[20];
	keyEvent.virtualKeyCode = keyCode;
	Awesomium::getKeyIdentifierFromVirtualKeyCode(keyEvent.virtualKeyCode,
												  &buf);
	strcpy(keyEvent.keyIdentifier, buf);
	delete[] buf;
	
	keyEvent.modifiers = 0;
	keyEvent.nativeKeyCode = 0;
	keyEvent.type = Awesomium::WebKeyboardEvent::TYPE_KEY_DOWN;
    
	webView->injectKeyboardEvent(keyEvent);
    
	keyEvent.type = Awesomium::WebKeyboardEvent::TYPE_KEY_UP;
    
	webView->injectKeyboardEvent(keyEvent);
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
    webView->injectMouseMove(x, y);
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
    webView->injectMouseMove(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
    webView->injectMouseDown(Awesomium::LEFT_MOUSE_BTN);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){
    webView->injectMouseUp(Awesomium::LEFT_MOUSE_BTN);
}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}