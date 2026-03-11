import '../App.css'
import './home.css'

export function Home() {
    return ( 
    <>
        <div className = "HomePage">   
            <h1 className = "hometitle"> "The Hangout" Minecraft Server </h1> 
            <div className = "aboutHome">
                <u> <h2 className = "heading"> ABOUT </h2> </u>
                <b className = "text"> Welcome to <i>"<u>The Hangout!</u>"</i> This server is a place where creativity, adventure, and teamwork come together. 
                Regardless if you're a casual player, or an experienced player there is something for everyone here! 
                At <i>"<u>The Hangout</u>"</i>, our main goal here is simple, to have fun and express yourself, along with exploring the world to see what these new updates brought us.
                Join us and become part of a growing community where every player is valued. Let's build, explore, and have a good time! 
                </b>
            </div> 

            {/* div needed to set up horizaontal boxes */}
            <div className = "horizontal"> 
                <div className = "hBOX">
                    <u> <h2 className = "heading"> JOIN THE TEAM! </h2> </u>
                    <b className = "text"> (discuss members here) </b>
                </div> 
                <div className = "hBOX">
                    <u> <h2 className = "heading"> OUR GOALS </h2> </u>
                    <b className = "text"> (dicuss server goals/tasks here) </b>
                </div> 
            </div>
        </div>
    </>
    )
}

export default Home