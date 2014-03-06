## Tutorial

1. Drag PushPanel.framework from Finder to your XCode project (into YourApp -> Frameworks folder on the left). Click OK.

2. Get your project's "token" string (just drop us an email to hi@pushpanel.io to get your token). Somewhere at the top of AppDelegate.m add the following line


		#define PUSHPANEL_TOKEN @"<your_project_token>"


3. In all files where you want to use PushPanel, import it first by adding the following line to your code:

		#import <PushPanel/PushPanel.h>

4. You can change PushPanel log level by calling. See PushPanel.h for more details. By default there is no logging.

		[PushPanel setLogLevel:PushPanelLogLevelOnlyErrors];

5. In your AppDelegate.m inside the method application:didFinishLaunchingWithOptions:launchOptions: add the following line:

		[PushPanel initSharedInstanceWithToken:PUSHPANEL_TOKEN];

6. To identify your user within PushPanel (either you use user authentication method or no authentication at all), put the following line where appropriate (as a way of "identifying" your user inside PushPanel object).

		[[PushPanel sharedInstance] registerUser:<unique_id>];

	For example, if you don't use user authentication, you can identify your user right away after calling initSharedInstanceWithToken: from section 5 of this tutorial. If you use user authentication, then it's best to call registerUser: right after registering/authorizing your user inside your app.

	As <unique_id> you can use your user ID from your database. If you don't have backend, then you can use whatever you want as user identifier, for example, device ID.

7. In the place of your app, where you want to handle "Log out" action for your user add the following line:

		[[PushPanel sharedInstance] logoutUser];

	After calling this, your app stops receiving notifications for this user, until you call registerUser: for another user session.

8. Done!