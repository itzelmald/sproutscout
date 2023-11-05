#Sprout Scouts: Smart Remote Plant Monitoring Project
## Abstract

This project aims to solve the problem of effectively monitoring and maintaining the health of plants using sensors, to track temperature, humidity, light, and moisture levels. The goal of this project and our approach is to provide users with real-time data and notifications about their plant’s conditions and needs, and potentially allow them to make necessary changes in response remotely. A solution to this problem is relevant on a societal scale due to the way in which it contributes to more responsible plant ownership which can lead to positive impacts on the environment and farming sustainability. Moreover, it could potentially be applied on a grander level, as food insecurity is an issue that afflicts on a global scale and can be exacerbated by poor farming practices and plant health management, which our project attempts to address. From the current body of work, there seems to be limited research on smaller scale projects such as singular household gardens or “homesteads”. There is a greater need for more focus on and attention on creating accessible, sustainable and cost-effective IoT solutions in home gardening, and indoor plants, which is what this project is concentrated on.  Our solution fills this gap by providing a unique approach to smart plant monitoring on a minute scale in a household where space for maintaining a farm or garden may be very limited for the user, but provides the user with a  similar user experience and features to those used on industrial farms in smart agriculture. 

## Introduction
As global food scarcity and rising food prices creep upon us, plant monitoring has become more important than ever [1]. One of the major factors of crop losses is contributed to poor plant health. Factors such as soil moisture, light, humidity levels, and temperature can all affect a plant’s growth, which makes monitoring of these environmental factors key in proper plant care [2]. There has been a growing interest in local food production, and more specifically home gardens, to improve food-security and nutrition at a local and household level [3]. In addition, due to the recent COVID-19 pandemic, many turned to gardening which showed to provide potential health benefits [4]. Household gardening has shown its prominence for dietary and nutritional reasons as well as simply being a fun hobby for many people. Other smart agriculture implementations have focused on integrated homestead automation systems using IoT technologies and addressing the unique challenges that regular people, who may perhaps not have hundreds of acres of land to be able to establish self-sustaining homesteads and small farming projects [5]. Previous research has placed more emphasis on issues such as water scarcity in agriculture, and how to promote more efficient water usage in farming. Moreover, there has also been research centered around making smart agriculture globally accessible through integrations with the Blynk app and NodeMCU [6]. Small-scale remote plant monitoring systems on the market today are costly and typically serve to monitor one aspect of plant health. In addition, many of these systems do not offer automatic plant care, or only offer a watering or light solution. Our solution aims to provide a unique approach to smart-plant monitoring by allowing users to monitor and control plant health in real-time from a smartphone. Our system will track soil moisture, humidity, temperature, and light levels. An automatic irrigation and lighting system will also be used, with thresholds controlled within the smartphone application. Notifications will also be sent to the user about the plant health when the aforementioned thresholds are passed. In addition, our solution will implement an energy-saving sleep cycle using real-time weather forecasts. Given our solution, users will be able to remotely monitor plant health and control the automation of the watering and lighting system all through a smartphone app. Our cost-effective solution will surpass the abilities of the current small-scale plant monitoring products due to its various plant-health parameters, automation, personalization, and energy-saving features. Our system will make remote plant monitoring accessible to more users, which can aid in overall plant health and plant care decisions. 

##System Design


## 3.1 Process Model Specification

## Process Specification
This system will address the problem of whether it is possible to create an energy efficient system that allows users to care for their plants remotely through an app. This is defined through the use of multiple ESP32 devices that can be deployed as nodes to monitor and manage the health of plants in a household. However, this system’s scope can be extended to a larger network of nodes that interface over a farm. The plant will be managed through the use of actuators such as lights and a watering system in response to specific plant conditions. The app will be able to gather plant health metrics information using light, temperature, humidity, and moisture levels collected from the respective sensors. 

## Information Model Specification

#### Figure 1: Entity Relations
As shown in the diagram, the main virtual entities will be each separate plant. The plant entity contains the temperature, soil moisture, and light level attributes. All plant entities share a common attribute of the current weather as every plant will be in the same garden module. Each plant entity will also have its own water pump and lamp. The water pump and lamp entity have the same “state” attribute, defining whether the entity is powered or not. 

### Service Specification
The backend service we will be utilizing is Supabase. Supabase supports deploying cloud-hosted API endpoints that we will be using to have the device upload data to the database. The Supabase JavaScript SDK will be used to retrieve  data from the database on the mobile app. The device sensors are inputs which send data to an API, and the API in turn securely updates the database. The mobile app displays the outputs when a user clicks on a plant to view the data that has been stored about it.

### IOT Level Specification
The two devices will engage in a server-client process to facilitate this process, with the receiver acting as the client to gather and collect data that will then be sent to the server, which will then send the collected information from our sensors over to the API. With a bidirectional flow of communication, the project API will be able to collect and store the data in a cloud environment with a database that communicates with the app, relay and receive information from the user.

#### Figure 2: Deployment Levels

### Functional View Specification
In this system, the two ESP32 IoT devices, along with actuators and sensors that we use to gather and collect information on the plant health metrics. These would be associated and mapped into the device and management functional groups. In the services functional group, would be the web services and REST services. In the communication management groups would be the HTTP requests and APIs we use to gather information from the devices. The application functional group would include the actual application along with the database server. Lastly, the application management and database management would go into the management functional group.

### Operational View Specification
Two ESP32 devices will communicate with each other to send and receive information regarding the data collected about plant status from the moisture, temperature, and light sensors, with an API that receives this data. The API will have defined endpoints for sending data from one ESP32, which will act as the sender, and retrieving data from the other (the receiver). The API will support necessary methods for the data exchange with appropriate headers, credentials, and response codes. 

The service provided by this system is the enablement of the user to receive information regarding the status of their plant on the various temperature, light, and moisture levels, with the ability to customize safe parameters for plants and make adjustments remotely to the light levels that the plant is receiving by activating or deactivating the light. The application will be a React application that connects Firebase/Supabase backend to store information and enable features like user authentication, real-time database listeners, and push notifications. 

### Device and Component Integration
Once the specification for the IoT system has been met the prototype should be integrated in manner as represented by the TinkerCad 3D model as shown below in Figures 3, 4, and 5. 

#### Figure 3: Device and Component Integration


#### Figure 4: Pins used in the setup


#### Figure 5: Side view of the setup


### Application Development
The Arduino IDE libraries that will be used in client-server processes are “HTTPClient.h”, which will enable our code for the devices to be able to handle HTTP requests and the data received. The “Wifi.h” library will also be used to enable the devices to complete the receive and handoff by enabling connection to the internet, along with the “WifiClient.h” and “WifiSever.h” libraries. The “AsyncHTTPClient”  library is used for asynchronous requests. 

The companion mobile application will be developed in JavaScript, utilizing the React Native framework to achieve cross-compatibility between iOS and Android. The backend, which will facilitate communication between the Arduino device and the mobile app, will be powered by Supabase, a backend-as-a-service platform which will enable us to develop highly scalable infrastructure at little upfront cost. Data captured by the on-device sensors will be stored inside a PostgreSQL database.

The mobile app will show users a ‘Dashboard’ view containing cards of all of the plants registered to their account. Users will be able to press on any of these cards to get an in-depth view of all the health metrics that sensors have captured about the plant’s current condition. They will also be able to manage properties about that plant, such as its display name.

### 3.2 Measurements and Metrics for Testing
As the development of the IoT system proceeds we will perform a series of iterative testing methods on the prototype to ensure that it meets the defined objectives and requirements. This will look like performing a series of functional tests to ensure that our devices are connecting and deploying information to our database in a succinct manner, unit testing on our backend and frontend development integrations.

We will observe and collect data on changes in power consumption as a way of measuring the energy efficiency of IoT devices and optimize for extended battery life. We will also measure the end to end latency in how much time (in milliseconds) information takes to travel from different nodes in our system, along with latency due to data processing. Through this iterative process changes will be made to make necessary adjustments as needed and implement error handling.  

### 3.3 Plan for Evaluating Performance and Demoing 
As we build the different components of the system, we will be testing each component separately before integrating all units together. These different components include the sensor data collection, irrigation system, lighting system, networking, application interface, and the various application features. We will be using two plants to test our system. To evaluate performance we will assess rates of failure and uptime, or percentage of time the system is operational, and how well power consumption is managed. We will also measure performance metrics such as latency between the server and the device, as well as execution time for the API endpoints.

To demonstrate how our system works we will show how the information is displayed in the app to the user and an example of how they can manage their plants remotely through one of the parameters, such as by setting the state of one of the actuators. 

### 3.4 Target User and Scenario
Our project is aimed towards small scale or household gardens. Since other works have focused on large-farm based plant monitoring systems, we hope to provide a solution for small scale farmers that is accessible, sustainable and cost-effective. Users will be able to remotely monitor plant moisture, light, and temperature levels from their smartphone, which will display and send notifications in real-time regarding the plant health. Users will also have the ability to control certain thresholds at which the plants will automatically be watered or be provided with a light source. In addition, the system will implement a sleep-cycle based on real-time weather data to save energy. 

Users can step away from their garden for long periods of time without having to worry about the health and care of their plants. Since important plant-health properties will be monitored in real-time, the users can make more informed decisions on the care of their plants, removing some of the uncertainty regarding plant health. 

### 3.5 Privacy and Security Considerations

Supabase, our backend-as-a-service platform of choice, has a built-in secure authentication service that we plan to use to secure user data within our app. We plan to implement standard username/password credential sign-in, and eventually secure accounts even further with two-factor authentication and Single Sign-On (SSO) through social providers. Our IoT devices will communicate with our database through Edge functions, which will be secured through API access tokens to ensure that all requests are authentic. We will not transmit identifiable user data to any third-party, including for advertising or analytics purposes, to protect user privacy. We will, however, have to store location data about where plants are to enable functionality related to the surrounding climate and weather conditions.

## References

[1] J. Flood, “The importance of plant health to food security,” Food Security, vol. 2, no. 3, pp. 215–231, Jul. 2010, doi: https://doi.org/10.1007/s12571-010-0072-5.

[2] S. Siddagangaiah, “A Novel Approach to IoT Based Plant Health Monitoring System,” International Research Journal of Engineering and Technology (IRJET), vol. 3, no. 11, pp. 880–886, Nov. 2016.

[3] D. H. Galhena, R. Freed, and K. M. Maredia, “Home gardens: a promising approach to enhance household food security and wellbeing,” Agriculture & Food Security, vol. 2, no. 1, May 2013, doi: https://doi.org/10.1186/2048-7010-2-8.

[4] J. Corley, J. A. Okely, A. M. Taylor, D. Page, and M. Welstead, “Home garden use during COVID-19: Associations with physical and mental wellbeing in older adults,” Journal of Environmental Psychology, vol. 73, pp. 1–8, Feb. 2021, doi: https://doi.org/10.1016/j.jenvp.2020.101545.

[5] J. Xu, B. Gu, and G. Tian, “Review of agricultural IoT technology,” Artificial Intelligence in Agriculture, vol. 6, Jan. 2022, doi: https://doi.org/10.1016/j.aiia.2022.01.001.

[6] “Smart Gardening Automation using IoT With BLYNK App,” IEEE Conference Publication | IEEE Xplore, Apr. 01, 2019. https://ieeexplore.ieee.org/abstract/document/8862591/ 

